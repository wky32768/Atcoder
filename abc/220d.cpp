#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[120005],f[120005][12];
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(f,0,sizeof f);
	f[1][a[1]]=1;
	for(int i=2;i<=n;i++) for(int j=0;j<=9;j++) {
		f[i][(j+a[i])%10]=(f[i][(j+a[i])%10]+f[i-1][j])%mod;	
		f[i][(j*a[i])%10]=(f[i][(j*a[i])%10]+f[i-1][j])%mod;
	}
	for(int i=0;i<=9;i++) cout<<f[n][i]<<'\n';
	return 0;
}

