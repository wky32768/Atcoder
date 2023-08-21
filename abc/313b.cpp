#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define int long long
#define For(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 100005;
int n, m, x, y, ok[N];
signed main() {
    cin >> n >> m;
    For(i, 1, n) ok[i] = 1;
    For(i, 1, m) {
        cin >> x >> y;
        ok[y] = 0;
    }
    int ans = 0, have = 0;
    For(i, 1, n) {
        // cout << "debug " << i << " " << ok[i] << endl;
        if(ok[i] == 1) {
            if(!have) {have = 1; ans = i;}
            else {cout << "-1";return 0;}
        }
    }
    cout << ans;
    return 0;
}
