#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
const int N = 100005;
int n, v, a[N];
bool cmp(int a, int b) {
    return a > b;
}
signed main() {
    while(cin >> n >> v) {
        For(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1, cmp);
        int sum = 0;
        For(i, 1, v) sum += a[i];
        cout << sum << '\n';
    }
    return 0;
}