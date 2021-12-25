#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1000005;
int n,x[N],y[N],mx;
map <pair <int,int> ,int> v;
struct node {
	int next,to;
} a[N];
int read() {
	int f=1,x=0;
	char ch=getchar();
	while(!(ch>='0' && ch<='9')) { 
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();	
	}
	return f*x;
}
int head[N],cnt;
void add(int x,int y) {
	a[++cnt].next=head[x];
	a[cnt].to=y;
	head[x]=cnt;	
}
int layer[N];
bool is_fa[N],vis[N];
void dfs(int x,int l) {
//	cout<<"dfs "<<x<<" "<<l<<'\n';
	layer[l]++;
	vis[x]=1;
	mx=max(mx,l);
	for(int i=head[x];i;i=a[i].next) {
		int t=a[i].to;
		if(!vis[t]) dfs(t,l+1);
	}
}
signed main() {
	cin>>n;
	For(i,1,n) {
		x[i]=read(),y[i]=read();
		v[make_pair(x[i],y[i])]=i;
		is_fa[i]=1;
	}
	For(i,1,n) {
		if(v[make_pair(x[i]-1,y[i])]) {
			int now=v[make_pair(x[i]-1,y[i])];
			is_fa[now]=0;
			add(i,now);
		}
		if(v[make_pair(x[i],y[i]-1)]) {
			int now=v[make_pair(x[i],y[i]-1)];
			is_fa[now]=0;
			add(i,now);
		}
	}
	int ans=0;
	For(i,1,n) if(is_fa[i] && (!vis[i])) {
		mx=0;
		dfs(i,1);	
		int ans1=0,ans2=0;
		for(int j=1;j<=mx;j+=2) ans1+=layer[j];
		for(int j=2;j<=mx;j+=2) ans2+=layer[j];
		ans+=max(ans1,ans2);
		For(j,1,mx) layer[j]=0;
	}
	cout<<ans;
	return 0;
}

