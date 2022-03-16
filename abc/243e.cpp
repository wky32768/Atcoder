#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=305;
const int M=45005;
int n, m, ans, a, b, c;
int dis[N][N];
signed main() {
    cin>>n>>m;
    memset(dis, 0x3f3f3f3f, sizeof dis);
    For(i,1,n) dis[i][i]=0;
    For(i,1,m) {
        cin>>a>>b>>c;
        dis[a][b]=min(dis[a][b], c);
        dis[b][a]=min(dis[b][a], c);
    }
    For(k,1,n) For(i,1,n) For(j,1,n)
        dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
    /*
    代码の问题:如果两个点之间有多条边就失效
    For(i,1,m) {
        For(k,1,n) if(x[i].a!=k && x[i].b!=k) 
                if(dis[x[i].a][k]+dis[k][x[i].b]<x[i].c) {ans++; break;}
    } //考虑每一条边, 如狗这两个点之间的最短路可以被取代, 那么这条边就可以被删除.
    */
//    cerr<<"dis[1][3]="<<dis[1][3]<<'\n';
   For(i,1,n) For(j,1,n) if(i!=j) {
        bool ok=1;
        For(k,1,n) if(i!=k && j!=k)
            if(dis[i][j]==dis[i][k]+dis[k][j]) ok=0;
        ans+=ok;
        // cerr<<"debug "<<i<<" "<<j<<" "<<ok<<'\n';
    }
    cout<<m-ans/2<<'\n';
    return 0;
}