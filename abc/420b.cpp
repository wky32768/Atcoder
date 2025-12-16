#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

const int N = 1e5 + 5;

using namespace std;

int n, m, score[N];
char ch[105][105];

signed main() {
    cin >> n >> m;
    For(i, 1, n) scanf("%s", ch[i] + 1);
    For(i, 1, m) {
        int tot0 = 0, tot1 = 0;
        For(j, 1, n) {
            if(ch[j][i] == '0') tot0++;
            else tot1++;
        }
        if(tot0 == 0 || tot1 == 0) {
            For(j, 1, n) score[j] ++;
        } else {
            if(tot0 <= tot1) {
                For(j, 1, n) if(ch[j][i] == '0') score[j] ++;
            } else {
                For(j, 1, n) if(ch[j][i] == '1') score[j] ++;
            }
        }
    }
    int mx = 0;
    For(i, 1, n) mx = max(mx, score[i]);
    For(i, 1, n) if(score[i] == mx) cout << i << " ";


    return 0;
}