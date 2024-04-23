#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int N = 1e5 + 5;

int n, m;
string ch[N];

signed main() {
    cin >> n >> m;
    For(i, 1, n) cin >> ch[i];
    sort(ch + 1, ch + n + 1);
    For(i, 1, n) cout << ch[i];




    return 0;
}