#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
#define mp make_pair

using namespace std;

const int N = 1e6 + 5;

int n, m;
int a[N], b[N], tot[N];

using namespace std;
signed main() {
    cin >> n >> m;
    For(i, 1, m) {
        cin >> a[i] >> b[i];
        tot[(a[i] + b[i]) % n] ++;
    }
    int ans = 0;
    For(i, 0, n - 1) ans += tot[i] * (m - tot[i]);
    cout << ans / 2 << endl;

    return 0;
}
