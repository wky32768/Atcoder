#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>

#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long

const int N = 3e5 + 5;
const int mod = 998244353;
using namespace std;

int n, a[N], b[N], f[N][2];
//f: in ith number, last one fliped(1/0)

void add(int &x, int y) {
    x = (x + y) % mod;
}

signed main() {
    cin >> n;
    For(i, 1, n) cin >> a[i] >> b[i];
    f[1][0] = f[1][1] = 1;
    For(i, 2, n) {
        if(a[i] != a[i - 1]) add(f[i][0], f[i - 1][0]);
        if(a[i] != b[i - 1]) add(f[i][0], f[i - 1][1]);
        if(b[i] != a[i - 1]) add(f[i][1], f[i - 1][0]);
        if(b[i] != b[i - 1]) add(f[i][1], f[i - 1][1]);
    }
    cout << (f[n][0] + f[n][1]) % mod << '\n';
    return 0;
}