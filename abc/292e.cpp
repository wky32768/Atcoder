#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 200005;
int n, m, cnt, head[N];
int x[N], y[N];
struct node {
    int next, to;
} sxd[N];
void add(int u, int v) {
    sxd[++cnt] = (node) {head[u], v};
    head[u] = cnt;
}
bool haveline[2005][2005], vis[2005];

void dfs(int x, int fa) {
    vis[x] = 1;
    for(int i = head[x]; i; i = sxd[i].next) {
        int to = sxd[i].to;
        if(to == fa) continue;
        if(vis[to]) continue;
        dfs(to, x);
    }
}

signed main() {
    cin >> n >> m;
    For(i, 1, m) {
        cin >> x[i] >> y[i];
        add(x[i], y[i]); 
        haveline[x[i]][y[i]] = 1;
    }
    int ans = 0;
    For(i, 1, n)  {
        For(j, 1, n) vis[j] = 0;
        dfs(i, 0);
        For(j, 1, n) if(j != i && vis[j]) {
            if(!haveline[i][j]) ans ++;
        }
    }
    
    cout << ans << '\n';
    return 0;
}