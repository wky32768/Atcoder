#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

const int N = 2e5 + 5;

int n, q, a[N], b[N], tot;

using namespace std;
signed main() {
    cin >> n >> q;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];
    For(i, 1, n) tot += min(a[i], b[i]);
    while(q--) {
        int x, v;
        cin >> x >> v;
        
    }



    return 0;
}