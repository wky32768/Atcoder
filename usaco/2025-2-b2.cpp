#include <bits/stdc++.h>

#define For(i, a, b) for(int i = a;i <= b;i++)

using namespace std;

const int N = 200005;

int n, a[N], ans;

signed main() {
    cin >> n;
    For(i, 1, n) {
        int x; cin >> x;
        a[x] ++;
    }
    For(i, 0, n) {
        if(!a[i]) {
            cout << ans << '\n';
            ans++;
        } else {
            cout << max(a[i], ans) << '\n';
        }
    }
    
    return 0;
}