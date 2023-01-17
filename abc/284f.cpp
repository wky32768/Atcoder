#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int p = 131;
const int mod = 998244353;
const int N = 2000005;

int n, fro[N], beh[N], pw[N];
char ch[N];

signed main() {
    cin >> n;
    scanf("%s", ch + 1);
    pw[0] = 1;
    For(i, 1, n) pw[i] = pw[i - 1] * p % mod;
    fro[0] = 1;
    For(i, 1, n * 2) 
        fro[i] = (fro[i - 1] * p % mod + ch[i] - 'a') % mod;
    beh[n * 2 + 1] = 1;
    for(int i = n * 2; i >= 1; i--) 
        beh[i] = (beh[i + 1] * p % mod + ch[i] - 'a') % mod;
    // For(i, 1, 3) cout << fro[i] << " " << beh[i] << '\n';
    For(i, 1, n) {
        // cout << i << " " << (fro[i] - fro[0] * pw[i] + mod) % mod << " " << (beh[n + 1] - beh[i + n + 1] * pw[i] % mod + mod) % mod << '\n';
        if((fro[i] - fro[0] * pw[i] % mod + mod) % mod != (beh[n + 1] - beh[i + n + 1] * pw[i] % mod + mod) % mod) continue;
        if((fro[n * 2] - fro[i + n] * pw[n - i] % mod + mod) % mod != (beh[i + 1] - beh[n + 1] * pw[n - i] % mod + mod) % mod) continue;
        for(int j = n + i;j >= i + 1; j--) cout << ch[j];
        cout << "\n" << i;
        return 0;
    }
    puts("-1");
    return 0;
}