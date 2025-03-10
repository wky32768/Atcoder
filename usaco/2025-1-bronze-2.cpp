#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long
using namespace std;
const int N = 1000005;
vector <int> a[N];
int n, f[N], distinct[N];
signed main() {
    cin >> n;
    For(i, 1, n) {
        cin >> f[i];
        a[f[i]].push_back(i);
        if(a[f[i]].size() == 1) distinct[i] = distinct[i - 1] + 1;
        else distinct[i] = distinct[i - 1];
    }
    int ans = 0;
    For(i, 1, n) {
        if(a[i].size() < 2) continue;
        // ans += a[i][a[i].size() - 2] - 1 - (a[i].size() - 2);
        if(a[i].size() == 2)
            ans += distinct[a[i][a[i].size() - 2] - 1];
        else 
            ans += distinct[a[i][a[i].size() - 2] - 1] - 1;
    }
    cout << ans << endl;
    return 0;
}