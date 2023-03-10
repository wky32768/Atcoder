#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 6e5 + 5;

int head[N], n, m, cnt, x, y, tot_e, tot_v;
bool vis[N];
struct node {
    int next, to;
} sxd[N];

void add(int u,int v) {
    sxd[++cnt]=(node) {head[u],v};
    head[u]=cnt;
} 

void dfs(int now) {
    vis[now] = 1;
    tot_v ++;
    for(int i = head[now]; i; i = sxd[i].next) {
        tot_e ++;
        if(!vis[sxd[i].to]) {
            dfs(sxd[i].to);
        }
    }
}

signed main() {
    cin >> n >> m;
    For(i, 1, m) {
        cin >> x >> y;
        add(x, y); add(y, x);
    }
    For(i, 1, n) if(!vis[i]) {
        tot_e = tot_v = 0;
        dfs(i);
        // cout << tot_e << " " <<  tot_v << endl;
        if(tot_e != tot_v * 2) {puts("No"); return 0;}
    }
    puts("Yes");
    return 0;
} 