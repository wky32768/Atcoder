#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int q, n, a[105];


signed main() {
    cin >> q;
    while(q--) {
        cin >> n;
        int ans = 0;
        For(i, 1, n) {
            cin >> a[i];
            if(a[i] % 2 ==1) ans ++;
        }
        cout << ans << '\n';


    }

    return 0;
}