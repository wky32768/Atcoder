#include <bits/stdc++.h>

#define For(i, a, b) for(int i = a;i <= b;i++)

using namespace std;

const int N = 505;

int n, k, q, r, c, v;
int a[N][N], sum[N][N], mx;

signed main() {
    cin >> n >> k >> q;
    For(i, 1, q) {
        cin >> r >> c >> v;
        For(j, max(1ll, r - k + 1ll), r) 
            For(l, max(1ll, c - k + 1ll), c) {
                sum[j][l] = sum[j][l] + v - a[r][c];
                mx = max(mx, sum[j][l]);
            }
        a[r][c] = v;
        cout << mx << endl;
    }
    return 0;
}