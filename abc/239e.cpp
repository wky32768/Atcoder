#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int n,q,x[N],sorted[N][25];
bool vis[N];
vector <int> v[100005];
void dfs(int now) {
//	cout<<"Debug "<<now<<'\n';
	vis[now]=1;
	For(i,1,20) if(sorted[now][i]<x[now])  {
		For(j,i+1,20) sorted[now][i]=sorted[now][i-1];
		sorted[now][i]=x[now];
		break;
	}
	For(i,0,v[now].size()-1) {
		int to=v[now][i];
		if(vis[to]==1) continue;
		dfs(to);
		int a=1,b=1,temp[21];
		For(j,1,20) {
			if(sorted[now][a]>sorted[to][b]) {
				temp[j]=sorted[now][a];
				a++;
			} else {
				temp[j]=sorted[to][b];
				b++;	
			}
		}
		For(j,1,20) sorted[now][j]=temp[j];
	}
//	cout<<"check "<<now<<'\n';
//	For(i,1,20) cout<<sorted[now][i]<<" ";
//	puts("");
	return;
}
signed main() {
	cin>>n>>q;
	For(i,1,n) cin>>x[i];
	For(i,1,n-1) {
		int xx,yy;
		cin>>xx>>yy;
		v[xx].push_back(yy);
		v[yy].push_back(xx);
	}
	memset(vis,0,sizeof vis);
	dfs(1);
	while(q--) {
		int xx,yy;
		cin>>xx>>yy;
		cout<<sorted[xx][yy]<<'\n';	
	}
	return 0;
}

