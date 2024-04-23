#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int N = 1e5 + 5;

int a[5];

signed main() {

    For(i, 1, 3) cin >> a[i];
    sort(a + 1, a + 4);
    if (a[1] == 5 && a[2] == 5 && a[3] == 7) cout << "YES";
    else cout << "NO";
    return 0;
}