#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
#define mp make_pair

using namespace std;

const int N = 5e3 + 5;


int n, x, y, a[N], b[N], f[N][N]; // 第i个怪物, 使用j的体力, 最少的魔力消耗


using namespace std;
signed main() {

    cin >> n >> x >> y;
    For(i, 1, n) cin >> a[i] >> b[i];
    For(i, 0, N - 1) For(j, 0, N - 1) f[i][j] = 1e18;
    
    f[0][0] = 0;
    For(i, 1, n) For(j, 0, x) {
        f[i][j] = min(f[i][j], f[i - 1][j] + b[i]);
        if(j + a[i] <= x) 
            f[i][j + a[i]] = min(f[i][j + a[i]], f[i - 1][j]);
    }
    int ans = 0;
    for(int i = n;i >= 0;i--) {
        int mn = 1e18;
        For(j, 0, x) mn = min(mn, f[i][j]);
        if(mn <= y) {
            cout << i << '\n';
            break;
        }
    }
    

    return 0;
}
