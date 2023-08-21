#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
const int N = 100005;
int t, n, f, a[N];
bool ok(double x) {
    int sum = 0;
    For(i, 1, n) {
        double temp = a[i] * acos(-1) / (x / a[i]);
        sum += (int)temp;
    }
    // cout << "ok " << x << " " << sum << '\n';
    return sum >= (f + 1);
}
signed main() {
    cin >> t;
    while(t--) {
        cin >> n >> f;
        For(i, 1, n) cin >> a[i];
        double l = 0.00001, r = 1e18, ans = 0;
        while(fabs(r - l) > 0.000001) {
            double mid = (l + r) / 2;
            if(ok(mid)) {
                ans = mid;
                l = mid;
            } else r = mid;
        }
        printf("%.4lf\n", ans);
    }
    return 0;
}