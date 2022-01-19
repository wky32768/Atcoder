#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=300005;
int n,q,a[N],x[N],k[N];
map <int,vector <int> > mp;
signed main() {
	cin>>n>>q;
	For(i,1,n) {
		cin>>a[i];
		mp[a[i]].push_back(i);
	}
	For(i,1,q) {
		cin>>x[i]>>k[i];	
		if(mp[x[i]].size()>=k[i])
			cout<<mp[x[i]][k[i]-1]<<'\n';
		else puts("-1");
	} 
	return 0;
}
