#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n, head[400005], m;
struct node {
    int next, to;
} sxd[400005];
int cnt, ans;
bool vis[400005];
void add(int x, int y) {
    sxd[++cnt].next=head[x];
    sxd[cnt].to = y;
    head[x]= cnt;
}

void dfs(int now, int from) {
    ans ++;
    vis[now] = 1;
    if(ans >= 1000000) return;
    for(int i=head[now];i;i=sxd[i].next) {
        if(sxd[i].to != from && !vis[sxd[i].to]) 
            dfs(sxd[i].to, now);
    }
    vis[now] = 0;
}

signed main() {
    cin >> n >> m;
    For(i, 1,m) {
        int x, y;
        cin >> x >> y;
        add(x, y); add(y, x);
    }

    dfs(1, 1);
    cout << min(ans, 1000000ll);

    return 0;
}