#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int N = 1e5 + 5;

int n, m, no[N], ten[N];

bool ok(int x) {
    while(x) {
        if(no[x % 10]) return 0;
        x /= 10;
    }
    return 1;
}

signed main() {
    cin >> n >> m;
    For(i, 1, m) {
        int x;
        cin >> x;
        no[x] = 1;
    }
    For(i, n, 100000) {
        if(ok(i)) {
            cout << i;
            return 0;
        }
    }


    return 0;
}