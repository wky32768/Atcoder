#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=1005;
int n,a[N],c[N];
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int now=0;
	for(int i=1;i<=n;i++) {
		now=(now+a[i])%360;
		c[i]=now;
	}
	sort(c+1,c+n+1);
	int ans=0;
	for(int i=0;i<=n-1;i++) if(c[i+1]-c[i]>ans) ans=c[i+1]-c[i];
	ans=max(ans,360-c[n]);
	cout<<ans;
	return 0;
}
/*
90 270 315 150
*/
