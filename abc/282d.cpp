#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 200005;
int n, m, cnt, head[N << 1];
int coup[N], cate[N], conn[N];
int fa[N], fa_1[N], fa_2[N];
bool ok, vis[N];
struct node {
    int next, to;
} sxd[N << 1];

void add(int x, int y) {
    sxd[++cnt].next = head[x];
    sxd[cnt].to = y;
    head[x] = cnt;
}

void dfs(int x, int from) {
    fa[x] = from;
    vis[x] = true;
    for(int i = head[x]; i; i = sxd[i].next) {
        if(vis[sxd[i].to]) {
            if(cate[x] + cate[sxd[i].to] != 3) ok = 0;
        } else {
            cate[sxd[i].to] = 3 - cate[x];
            if(cate[sxd[i].to] == 1) fa_1[from] ++;
            if(cate[sxd[i].to] == 2) fa_2[from] ++;
            dfs(sxd[i].to, from);
        }
    }
}

signed main() {
    cin >> n >> m;
    For(i, 1, m) {
        int x, y; cin >> x >> y;
        add(x, y); add(y, x);
        coup[x] = coup[y] = 1;
        conn[x] ++; conn[y] ++;
    }
    ok = 1;
    For(i, 1, n) if(!vis[i] && coup[i] == 1) {cate[i] = 1; fa_1[i] = 1; dfs(i, i);}
    int tot_coup = 0, tot_1 = 0, tot_2 = 0;
    For(i, 1, n) {
        if(coup[i]) tot_coup ++;
        if(cate[i] == 1) tot_1 ++;
        if(cate[i] == 2) tot_2 ++;
    }
    if(ok == 0) puts("0");
    else {
        int ans = 0, tot_conn = 0;
        ans += tot_1 * tot_2;
        For(i, 1, n) tot_conn += conn[i];
        ans -= tot_conn / 2;
        ans += tot_1 * (tot_1 - 1) / 2;
        ans += tot_2 * (tot_2 - 1) / 2;
        For(i, 1, n) if(fa[i] == i)
            ans = ans - fa_1[i] * (fa_1[i] - 1) / 2 - fa_2[i] * (fa_2[i] - 1) / 2;
        ans += (n - tot_coup) * (n - tot_coup - 1) / 2;
        ans += (tot_1 + tot_2) * (n - tot_coup);
        cout << ans << '\n';
    }
    return 0;
} 