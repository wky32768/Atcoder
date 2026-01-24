#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 5e5 + 5;

int n, m;
int a[N], dis[N];

bool cmp(int a, int b) {
    return a > b;
}


using namespace std;
signed main() {
    cin >> n >> m;
    For(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    For(i, 1, n - 1) dis[i] = a[i + 1] - a[i];
    sort(dis + 1, dis + n, cmp);
    int sum  = 0;
    For(i, 1, m - 1) sum += dis[i];
    cout << a[n] - a[1] - sum << endl;



    return 0;
}
