#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int N = 1e5 + 5;

int n, a[105][105];


signed main() {
    cin >> n;
    For(i, 1, n) For(j, 1, n) cin >> a[i][j];
    For(i, 1, n) {
        For(j, 1, n)
            if(a[i][j]) cout << j << " ";
        puts("");
    }


    return 0;
}