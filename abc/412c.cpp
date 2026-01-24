#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 5e5 + 5;

int t, n, a[N];


int ef(int x) {
    int l = 1, r = n, ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[mid] <= x) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

using namespace std;
signed main() {
    
    cin >> t;
    while(t--) {
        cin >> n;
        For(i, 1, n) cin >> a[i];
        int st = a[1], ed = a[n];
        sort(a + 1, a + n + 1);
        bool ok = 1;
        int ans = 1;
        while(1) {
            int at = ef(st * 2);
            ans++;
            if(a[at] >= ed) break;
            if(a[at] == st) {ok = 0; break;}
            st = a[at];
        }
        if(ok) cout << ans << endl;
        else cout << -1 << endl;
    }

    return 0;
}
