#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,x,len[100005],ans;
vector <int> v[100005];
void dfs(int now,int rest) {
	if(now==n+1) {
		if(rest==1) ans++;
		return;
	}
	For(i,1,len[now]) if(rest%v[now][i]==0) {
		dfs(now+1,rest/v[now][i]);
	}
}
signed main() {
	cin>>n>>x;
	For(i,1,n){
		cin>>len[i];
		v[i].push_back(0);
		For(j,1,len[i]){
			int temp;
			cin>>temp;
			v[i].push_back(temp);	
		}
	}
	dfs(1,x);
	cout<<ans;
	return 0;
}
