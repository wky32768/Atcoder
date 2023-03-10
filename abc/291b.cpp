#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long

const int N = 1e5 + 5;
using namespace std;

int n, a[N];

signed main() {
    cin >> n;
    For(i, 1, n * 5) cin >> a[i];
    sort(a + 1, a + n * 5 + 1);
    double ans = 0;
    For(i, n + 1, n * 4) ans += a[i];
    cout << ans / (n * 3) << '\n';
    return 0;
}