#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define int long long
#define For(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 100005;
int n, a[N], mx;
signed main() {
    cin >> n;
    For(i, 1, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if(mx == a[1]) {
        int havesame = 0;
        For(i, 2, n) 
            if(a[i] == mx) {havesame = 1;break;}
        if(havesame) cout << "1";
        else cout << "0";
    } else {
        cout << mx - a[1] + 1;
    }
    return 0;
}
