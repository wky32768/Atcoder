#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
const int mod=998244353;
int pw[25];
signed main() {
	int n;
	cin>>n;
	int ws=0,count=n,ans=0;
	while(count) {ws++; count/=10;}
	pw[0]=1;
	for(int i=1;i<=18;i++) pw[i]=pw[i-1]*10; 
//	cout<<"ws="<<ws<<'\n';
	for(int i=1;i<=ws-1;i++) ans=(ans+(((pw[i]-pw[i-1])%mod)*((pw[i]-pw[i-1]+1)%mod)/2)%mod)%mod;
//	cout<<"ans="<<ans<<'\n';
	ans=(ans+(((n-pw[ws-1]+2)%mod)*((n-pw[ws-1]+1)%mod)/2)%mod)%mod;
	cout<<ans;
	return 0;
}

