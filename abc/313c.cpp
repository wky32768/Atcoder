#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define int long long
#define For(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 200005;
int n, a[N], b[N];
signed main() {
    cin >> n;
    int sum = 0;
    For(i, 1, n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    int num = sum / n;
    For(i, 1, sum % n) b[i] = num + 1;
    For(i, sum % n + 1, n) b[i] = num;
    sort(b + 1, b + n + 1);
    int ans = 0;
    For(i, 1, n) ans += abs(a[i] - b[i]);
    cout << ans / 2 << endl;

    return 0;
}
