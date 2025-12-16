#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 7600;
int n, a[N], b[N], ans[N + 5], f[N][N];
signed main() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];
    int baseans = 0;
    For(i, 1, n) {
        baseans += (a[i] == b[i]);
        f[i][i] = 0;
        if(i != n) f[i][i + 1] = (a[i + 1] == b[i]) + (a[i] == b[i + 1]) - (a[i] == b[i]) - (a[i + 1] == b[i + 1]);
    }
    For(len, 2, n - 1) {
        For(i, 1, n - len) {
            int j = i + len;
            f[i][j] = f[i + 1][j - 1] + (a[i] == b[j]) + (a[j] == b[i]) - (a[i] == b[i]) - (a[j] == b[j]);
        }
    }
    For(i, 1, n) For(j, i, n) ans[f[i][j] + baseans]++;
    For(i, 0, n) cout << ans[i] << endl;







    return 0;
}