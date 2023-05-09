#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 500005;

int n, a[N];

signed main() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) if(a[i] % 2 == 0) cout << a[i] << " ";
    return 0;
}