#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 200005;
int n, q, a[N], opt, k, x;

signed main() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    cin >> q;
    while(q--) {
        cin >> opt;
        if(opt == 1) {
            cin >> k >> x;
            a[k] = x;
        } else {
            cin >> k;
            cout << a[k] << endl;
        }
    }
    return 0;
}