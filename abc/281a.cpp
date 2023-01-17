#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n;

signed main() {
    cin >> n;
    for(int i = n; i >= 0; i--) cout << i << '\n';
    return 0;
}