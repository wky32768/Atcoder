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

int x, y, a[N], b[N], c[N];
map <int, int> mp;

signed main() {
    cin >> x >> y;
    For(i, 1, x) cin >> a[i];
    For(i, 1, y) cin >> b[i];
    For(i, 1, x) c[i] = a[i];
    For(i, x + 1, x + y) c[i] = b[i - x];
    sort(c + 1, c + x + y + 1);
    For(i, 1, x + y) mp[c[i]] = i;
    For(i, 1, x) cout << mp[a[i]] << " ";
    puts("");
    For(i, 1, y) cout << mp[b[i]] << " ";
    return 0;
}