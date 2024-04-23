#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; ++i)
#define int long long

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int n;


signed main() {
    cin >> n;
    cout << n * (n + 1) / 2;
    return 0;
}