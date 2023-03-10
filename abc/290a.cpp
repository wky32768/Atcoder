#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 2e5 + 5;

int n, m, ans;
int a[N], b[N];

signed main() {
    cin >> n >> m;
    For(i, 1, n) cin >> a[i];
    For(i, 1, m) {
        cin >> b[i];
        ans += a[b[i]];
    }
    cout << ans;
    return 0;
} 