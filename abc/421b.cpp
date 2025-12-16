#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 1e5 + 5;

int rev(int x) {
    int res = 0;
    while(x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int a[21];
signed main() {
    int x, y;
    cin >> x >> y;
    a[1] = x, a[2] = y;
    For(i, 3, 10) a[i] = rev(a[i - 1] + a[i - 2]);
    cout << a[10] << endl;

    return 0;
}