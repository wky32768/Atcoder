#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
const int N = 300005;
int v, e, k, x[N], y[N], n, c[N], d[N];
signed main() {
    cin >> v >> e >> k;
    For(i, 1 ,e) cin >> x[i] >> y[i];
    cin >> n;
    For(i, 1, n) {
        For(j, 1, v) {cin >> c[j]; d[j] = c[j];}
        sort(d + 1, d + v + 1);
        int sum = 0;
        For(j, 1 ,v) if(d[j] != d[j - 1]) sum++;
        bool ok = 1;
        if(sum != k) ok = 0;
        For(j, 1 ,e) {
            if(c[x[j]] == c[y[j]]) {ok = 0; break;}
        }
        cout << (ok == 1 ? "Yes" : "No") << '\n';
    }
    return 0;
}