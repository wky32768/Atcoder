#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 3e5 + 5;

int n, k;
int a[N];
map <int, bool> mp;

signed main() {
    cin >> n >> k;
    For(i, 1, n) {cin >> a[i]; mp[a[i]] = 1;}
    int mex = 0;
    while(mp[mex] == 1) mex ++;
    cout << min(mex, k) << endl;
    return 0;
} 