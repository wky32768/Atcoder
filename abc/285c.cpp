#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 5005;
int n, ans;
char ch[N];


signed main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    ans = 0;
    For(i, 1, n - 1) ans += (int)pow(26, i);
    int ans2 = 0;
    For(i, 1, n) {
        ans2 = ans2 * 26 + (ch[i] - 'A');
    }
    cout << ans + ans2 + 1 << '\n';

    return 0;
} 