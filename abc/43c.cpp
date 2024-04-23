#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; ++i)
#define int long long

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int n, a[N];


signed main() {
    cin >> n;
    int sum = 0;
    For(i, 1, n) {
        cin >> a[i];
        sum += a[i];
    }
    int tar = 0;
    if(abs(sum % n) > abs(n) / 2) {
        tar = sum / n + (sum > 0 ? 1 : -1);
    } else {
        tar = sum / n;
    }
    // cout << tar << endl;
    int ans = 0;
    For(i, 1, n) {
        ans += (a[i] - tar) * (a[i] - tar);
    }
    cout << ans << endl;

    return 0;
}