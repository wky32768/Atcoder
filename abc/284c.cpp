#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n, head[100005], m;
struct node {
    int next, to;
} sxd[100005];
int cnt;
bool vis[100005];
void add(int x, int y) {
    sxd[++cnt].next=head[x];
    sxd[cnt].to = y;
    head[x]= cnt;
}

void dfs(int x, int from) {
    vis[x] = 1;
    for(int i = head[x]; i; i=sxd[i].next) {
        int to = sxd[i].to;
        if(to == from || vis[to]) continue;
        dfs(to, x);
    }
}

signed main() {
    cin >> n >> m;
    For(i, 1,m) {
        int x, y;
        cin >> x >> y;
        add(x, y); add(y, x);
    }
    int ans = 0;
    For(i, 1, n) if(!vis[i]) {
        ans ++;
        dfs(i, i);
    }
    cout << ans << endl;
    return 0;
}