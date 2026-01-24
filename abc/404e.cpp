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

int n, a[N], c[N], f[N]; // 把i位的东西运送到0需要的最少次数

using namespace std;
signed main() {
    cin >> n;
    For(i, 1, n - 1) cin >> c[i];
    For(i, 1, n - 1) cin >> a[i];
    memset(f, 0x3f3f3f3f, sizeof(f));
    f[0] = 0;
    For(i, 1, n - 1)
        For(j, i - c[i], i - 1)
            f[i] = min(f[i], a[j] ? 1 : f[j] + 1);
    int sum = 0;
    For(i, 1, n - 1) if(a[i]) sum += f[i];
    cout << sum << endl;

    return 0;
}
