#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

const int N = 1e5 + 5;

using namespace std;
signed main() {
    int x, y;
    cin >> x >> y;
    cout << (x + y - 1) % 12 + 1 << '\n';



    return 0;
}