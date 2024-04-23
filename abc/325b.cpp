#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define int long long
#define For(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N];

int calc(int x, int y) {
    int now = 0;
    if(x <= y) {
        For(i, 1, n) if(b[i] >= x && b[i] <= y) now += a[i];
    } else {
        For(i, 1, n) if(b[i] >= x || b[i] <= y) now += a[i];
    }
    return now;
}

signed main() {
    cin >> n;
    For(i, 1, n) cin >> a[i] >> b[i];
    int mx = 0;
    For(i, 0, 23) {
        mx = max(mx, calc(i, (i + 8) % 24));
    }
    cout << mx << '\n';
    return 0;
}
