#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int mod=998244353;
int n,k,m;
int ksm(int x,int y,int mod) {
	if(x%mod==0) return 0;
	int ans=1;
	while(y) {
		if(y%2==1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y/=2;
//		cout<<"ans "<<ans<<'\n';
	} 
	return ans;
}
signed main() {
	cin>>n>>k>>m;
//	int h=ksm(k,n);
//	int ans=ksm(m,h);
	int ans=ksm(m,ksm(k,n,mod-1),mod);
	cout<<ans<<'\n';
	return 0;
}

/*
mod=998244353
def ksm(x,y):
    ans=1
    while y!=0:
        if y%2==1:
            ans=(ans*x)%mod
        x=(x*x)%mod
        y=y//2
    return ans
n,k,m=map(int,input().split())
h=ksm(k,n)
ans=ksm(m,h)
print(ans%mod)
*/
