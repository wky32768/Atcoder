#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
#define int long long
const int N=400005;
int n, m, cnt, x, y, z;
int head[N], dis[N];
vector <int> rest;
struct node {
    int next, to, w, id;
} sxd[N];
void add(int u, int v, int w, int id) {
    sxd[++cnt].next=head[u];
    sxd[cnt].to=v;
    sxd[cnt].w=w;
    sxd[cnt].id=id;
    head[u]=cnt;
}
struct cd {
    int at, dis, useline;
    friend bool operator < (cd a, cd b) {
        return a.dis>b.dis;
    }
};
priority_queue <cd> q;
bool vis[N];
void dij() {
    memset(dis, 0x3f3f3f3f, sizeof dis);
    dis[1]=0;
    q.push((cd) {1, 0, 0});
    memset(vis, 0, sizeof vis);
	int tot=0; 
    while(!q.empty()) {
        cd now=q.top();
        // cout<<"initial now="<<now.at<<endl;
        while(vis[now.at]==1) {
            q.pop(); 
            if(q.empty()) goto L1;
            now=q.top();
            // cout<<"coming now="<<now.at<<endl;
        }
        // cout<<"now: "<<now.at<<'\n';
        q.pop();
        vis[now.at]=1;
        // tot++;
        if(now.dis==dis[now.at] && now.useline) {
            rest.push_back(now.useline);
            // cout<<"added: "<<now.useline<<'\n';
        }
        // if(tot==n) break;
        for(int i=head[now.at];i;i=sxd[i].next) {
            int to=sxd[i].to;
            // cout<<"to="<<to<<'\n';
            if(dis[to]>dis[now.at]+sxd[i].w) {
                dis[to]=dis[now.at]+sxd[i].w;
                // cout<<"dis[to]="<<dis[to]<<'\n';
                if(!vis[to]) q.push((cd) {to, dis[to], sxd[i].id});
            }
        }
        // cout<<"haha\n\n";
    }
    L1:;
}
signed main() {
    cin>>n>>m;
    For(i,1,m) {
        cin>>x>>y>>z;
        add(x, y, z, i); add(y, x, z, i);
    }
    dij();
    For(i,0,rest.size()-1) cout<<rest[i]<<" ";
    return 0;
}
