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


int t, n;
int a[N];

void dfs(int l, int r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    int lmin = 1e9, rmin = 1e9;
    For(i, l, mid) lmin = min(lmin, a[i]);
    For(i, mid + 1, r) rmin = min(rmin, a[i]);
    if(rmin < lmin) reverse(a + l, a + r + 1);
    dfs(l, mid);
    dfs(mid + 1, r);
}


using namespace std;
signed main() {

    cin >> t;
    while(t--) {
        cin >> n;
        For(i, 1, (1 << n)) cin >> a[i];
        dfs(1, (1 << n));      
        For(i, 1, (1 << n)) cout << a[i] << " ";
        puts("");
    }

    return 0;
}
