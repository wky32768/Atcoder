#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; ++i)
#define int long long

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int h, w, a, b;
int fac[N], inv[N];

int pow_mod(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void make_factor_inv() {
    fac[0] = 1;
    For(i, 1, N - 1) fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = pow_mod(fac[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % mod;
}

int C(int n, int m) {
    if(n < m) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

signed main() {
    make_factor_inv();
    cin >> h >> w >> a >> b;
    int ans = 0;
    For(i, 1, h - a) {
        // cout << "Debug " << i << " " << b + i - 1 << " " << b << " " << h - i + w - b - 1 << " " << h - i << endl;
        ans = (ans + C(b + i - 2, b - 1) * C(h - i + w - b - 1, h - i) % mod) % mod;
    }
    cout << ans << endl;

    return 0;
}