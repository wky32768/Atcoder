#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
const int N = 100005;
int n, m, a[N], t[N];
signed main() {
    while(cin >> n >> m) {
        t[0] = 0;
        For(i, 1 ,n) {
            cin >> a[i];
            t[i] = t[i - 1] + a[i];
        }
        int mx = -0x3f3f3f3f;
        For(i, 1, n - m + 1) {
            mx = max(mx, t[i + m - 1] - t[i - 1]);
        }
        cout << mx << '\n';
    }

    return 0;
}