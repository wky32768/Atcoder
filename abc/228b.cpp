#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n,k,a[N];
bool vis[N];
queue <int> q;
signed main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	vis[k]=1;
	q.push(k);
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		vis[now]=1;
		if(!vis[a[now]]) q.push(a[now]);	
	}
	int tot=0;
	For(i,1,n) if(vis[i]==1) tot++;
	cout<<tot<<'\n';
	return 0;
}
