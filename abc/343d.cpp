#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;

const int N = 2e5 + 5;

int n, t, a, b, num[N];
multiset <int> s;

signed main() {
    cin >> n >> t;
    For(i, 1, n) s.insert(0);
    int ans = 1;
    while(t--) {
        cin >> a >> b;
        int now = num[a];
        num[a] += b;
        s.erase(s.find(now));
        if(s.count(now) == 0) ans --;
        if(s.count(num[a]) == 0) ans ++;
        s.insert(num[a]);
        cout << ans << '\n';
    }
    return 0;
}