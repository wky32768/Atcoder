#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
#define mp make_pair

using namespace std;

const int N = 2e5 + 5;

vector <pair<int, int> > a[N];

int n, x[N], u, v, w, ans, sum[N], vis[N];

void dfs(int at) {
    sum[at] = x[at];
    for(auto i : a[at]) {
        int to = i.first, cost = i.second;
        if(to != at && !vis[to]) {
            vis[to] = 1;
            dfs(to);
            ans += abs(sum[to]) * cost;
            sum[at] += sum[to];
        }
    }

}


using namespace std;
signed main() {
    cin >> n;
    For(i, 1, n) cin >> x[i];
    For(i, 1, n - 1) {
        cin >> u >> v >> w;
        a[u].push_back(mp(v, w));
        a[v].push_back(mp(u, w));
    }
    dfs(1);
    cout << ans << endl;

    return 0;
}
