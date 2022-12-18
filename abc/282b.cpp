#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N =35;
int n, m, ans, ok[N][N];
char ch[N];

signed main() {
    cin >> n >> m;
    For(i, 1, n) {
        scanf("%s", ch + 1);
        For(j, 1, m) ok[i][j] = (ch[j] == 'o' ? 1 : 0);
    }
    For(i, 1, n) For(j, i + 1, n) {
        int okk = 1;
        For(k, 1, m) if(!ok[i][k] && !ok[j][k]) okk = 0;
        if(okk == 1) ans ++;
    }
    cout << ans;
    return 0;
}