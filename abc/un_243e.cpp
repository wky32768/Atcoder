#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<queue>
#define int long long
using namespace std;
const int maxn=305;
const int maxm=45005;
const int inf=1e12;
struct shu
{
    int u,id;
};
vector<int>g[maxn],w[maxn],idn[maxn];
int n,m,d[maxn],fa[maxn],vis[maxn]={0},q[maxn*maxn];
bool mark[maxm]={0};
inline int read() {
	int x=0, f=1;
	char ch=getchar();
	while(!(ch>='0' && ch<='9')) {
		if(ch=='-') f=-1;
		ch=getchar();
	}	
	while(ch>='0' && ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();	
	}
	return x*f;
}	
 
inline void init()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x=read(),  y=read(), z=read();
        g[x].push_back(y);
        w[x].push_back(z);
        idn[x].push_back(i);
        g[y].push_back(x);
        w[y].push_back(z);
        idn[y].push_back(i);
    }
}
 
inline void in()
{
    for(int i=1;i<=n;i++)
    d[i]=inf;
}
 
inline void spfa1(int x)
{
    int front=0,root=0;
    q[root++]=x;
    vis[x]=1;
    d[x]=0;
    while(front!=root)
    {
        int i=q[front++];
        vis[i]=0;
        for(int k=0;k<g[i].size();k++)
        {
            int j=g[i][k],c=w[i][k],z=idn[i][k];
            if(d[i]+c>=d[j]) continue;
            d[j]=d[i]+c;
            fa[j]=z;
            if(vis[j]) continue;
            q[root++]=j;
            vis[j]=1;
        }
    }
}
 
inline void spfa2(int x,int y)
{
    int front=0,root=0;
    q[root++]=x;
    vis[x]=1;
    d[x]=0;
    while(front!=root)
    {
        int i=q[front++];
        vis[i]=0;
        for(int k=0;k<g[i].size();k++)
        {
            int j=g[i][k],c=w[i][k],z=idn[i][k];
            if(d[i]+c>=d[j]) continue;
            if(z==y) continue;
            d[j]=d[i]+c;
            if(vis[j]) continue;
            q[root++]=j;
            vis[j]=1;
        }
    }
}
signed main()
{
    init();
    for(int i=1;i<=n;i++)//枚举起点。
    {
        in();
        fa[i]=0;
        spfa1(i);
        int s=0;
        for(int j=1;j<=n;j++)
        s+=d[j];
        for(int j=1;j<=n;j++)//枚举边。
        if(fa[j]&&!mark[fa[j]])
        {
            in();
            spfa2(i,fa[j]);
            int ss=0;
            for(int k=1;k<=n;k++)
              ss+=d[k];
            if(ss>s) mark[fa[j]]=1;//标记重要边。
        }
    }
    int tot=0;
    for(int i=1;i<=m;i++)
    if(mark[i]) tot++;
    cout<<m-tot<<'\n';
    return 0;
}
