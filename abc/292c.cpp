#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 3e5 + 5;

int n, ans;

signed main() {
    cin >> n;
    For(i, 1, n / 2) {
        int other = n - i;
        int ans1 = 0, ans2 = 0;
        For(j, 1, sqrt(i)) if(i % j == 0)
            ans1 += (j * j == i ? 1 : 2);
        For(j, 1 ,sqrt(other)) if(other % j == 0)
            ans2 += (j * j == other ? 1 : 2);
        // ans += (i * i == n ? ans1 * ans2 * 2 : ans1 * ans2);
        ans += (i * 2 == n ? ans1 * ans2 : ans1 * ans2 * 2);
    }
    cout << ans;
    return 0;
} 