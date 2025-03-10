#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long
using namespace std;

const int N = 2e5 + 10;
int t, n, m, a[N * 2];

int calc(int x, int l, int r) {
    int sum = 0;
    For(i, l, x - 1) sum += a[x] - a[i];
    For(i, x + 1, r) sum += a[i] - a[x];
    return sum;
}

signed main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        For(i, 1, n) {
            cin >> a[i];
            a[i] %= m;
        }
        sort(a + 1, a + n + 1);

        int ans = 1e18, ans1 = 1e18, ans2 = 1e18;
        if(n % 2 == 1) {
            ans = calc(n / 2 + 1, 1, n);
            int now = ans, mid = n / 2 + 1;
            For(i, 1, n - 1) {
                //把第i个移到第i+n个
                now -= a[mid] - a[i];
                now += a[i] + m - a[mid + 1];
                ans = min(ans, now);
                mid++;
                a[i + n] = a[i] + m;
            }
        } else {
            ans1 = calc(n / 2, 1, n);
            ans2 = calc(n / 2 + 1, 1, n);
            ans = min(ans1, ans2);
            int now1 = ans1, now2 = ans2, mid1 = n / 2, mid2 = n / 2 + 1;
            For(i, 1, n - 1) {
                now1 += (n / 2 - 1) * (a[mid1 + 1] - a[mid1]);
                now1 -= (n / 2) * (a[mid1 + 1] - a[mid1]);
                now1 -= a[mid1] - a[i];
                now1 += a[i] + m - a[mid1 + 1];
                ans = min(ans, now1);
                now2 += (n / 2) * (a[mid2 + 1] - a[mid2]);
                now2 -= (n / 2 - 1) * (a[mid2 + 1] - a[mid2]);
                now2 -= a[mid2] - a[i];
                now2 += a[i] + m - a[mid2 + 1];
                ans = min(ans, now2);
                mid1 ++; 
                mid2 ++;
                a[i + n] = a[i] + m;
            }
        }
        cout << ans << endl;
    }


    return 0;
}