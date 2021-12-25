#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n,x,y,sum1,sum2;
int a[1205],b[1205],f[1005][2805];
signed main() {
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>b[i];
		sum1+=a[i],sum2+=b[i];
	}
	if(sum1<x || sum2<y) {cout<<"-1";return 0;}
	for(int i=1;i<=n;i++) if(a[i]>=x && b[i]>=y) {cout<<"1";return 0;}
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	int ans=1e9;
	for(int i=1;i<=n;i++) {
		for(int j=900;j>=a[i];j--) for(int k=900;k>=b[i];k--) {
			f[j][k]=min(f[j][k],f[j-a[i]][k-b[i]]+1);
			if(j>=x && k>=y) if(f[j][k]<ans) ans=f[j][k];
		}
	}
	cout<<ans;
	return 0;
}

