//注意数组的初始化, 改多少复原多少!
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=600005;
int n, m, Q, cnt;
int head[N], dis[N];
struct node {
    int next, to;
} sxd[N];
//add an edge
void add(int u, int v) {
    sxd[++cnt].to = v;
    sxd[cnt].next = head[u];
    head[u] = cnt;
}
queue <int> q;
vector <int> ok;
signed main() {
    cin>>n>>m;
    For(i,1,m) {
        int x, y; cin>>x>>y;
        add(x, y); add(y, x);
    }
    memset(dis, -1, sizeof dis);
    cin>>Q;
    while(Q--) {
        int x, k;
        cin>>x>>k;
        int ans = 0;
        while(!q.empty()) q.pop(); q.push(x);
        ok.clear();
        dis[x]=0;
        while(!q.empty()) {
            int u=q.front(); q.pop();
            ok.push_back(u);
            if(dis[u]==k) continue;
            for(int i=head[u];i;i=sxd[i].next) {
                int v=sxd[i].to;
                if(dis[v]!=-1) continue;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
        For(i, 0, ok.size()-1) {ans+=ok[i]; dis[ok[i]]=-1;}
        cout<<ans<<endl;
    }
    return 0;
}
 