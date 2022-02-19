#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n,m,fa[N],d[N];
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
priority_queue <int> q;
vector <pair <int,int> > ans;
vector <int> temp;
signed main() {
	cin>>n>>m;
	For(i,1,n) cin>>d[i];
	For(i,1,n) fa[i]=i;
	For(i,1,m) {
		int x,y;
		cin>>x>>y;
		d[x]--,d[y]--;
		if(d[x]<0 || d[y]<0) {puts("-1"); return 0;}
		int xx=find(x),yy=find(y);
//		cout<<"debug "<<xx<<" "<<yy<<'\n';
		fa[xx]=yy;
	}
	For(i,1,n) if(d[i]>=1) q.push(i);
	while(!q.empty()) {
		if(q.size()==1) {puts("-1"); return 0;}	
		int one=q.top(); q.pop();
		temp.clear();
		int two=q.top(); q.pop();
		while(find(one)==find(two)) {
			if(q.empty()) {puts("-1"); return 0;}
			temp.push_back(two);
			two=q.top(); q.pop();	
		}
//		cout<<"??? "<<one<<" "<<two<<" "<<d[one]<<" "<<d[two]<<'\n';
		ans.push_back(make_pair(one,two));
		fa[find(one)]=find(two);
		d[one]--, d[two]--;
		if(d[one]>=1) q.push(one); if(d[two]>=1) q.push(two);
//		cout<<"temp.size()="<<temp.size()<<'\n';
		if(temp.size()>=1) For(j,0,temp.size()-1) {
//			cout<<"temp[j]="<<temp[j]<<'\n';
			q.push(temp[j]);
		}
//		puts("haha");
	}
	For(i,0,ans.size()-1) cout<<ans[i].first<<" "<<ans[i].second<<'\n';
	return 0;
}

