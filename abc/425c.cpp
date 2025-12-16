#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 5e5 + 5;

int n, q, a[N], opt, c, l, r, tot[N];

signed main() {
    cin >> n >> q;
    For(i, 1, n) {
        cin >> a[i];
        tot[i] = tot[i - 1] + a[i];
    }
    int at = 0;
    while(q--) {
        cin >> opt;
        if(opt == 1) {
            cin >> c;
            at = (at + c) % n;
        } else {
            cin >> l >> r;
            if(at + l >= 1 && at + r <= n)
                cout << tot[at + r] - tot[at + l - 1] << endl;
            else if(at + l > n) {
                cout << tot[at + r - n] - tot[at + l - n - 1] << endl;
            } else {
                cout << tot[n] - tot[at + l - 1] + tot[at + r - n] << endl;
            }
        }
    }
    
    return 0;
}