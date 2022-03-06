#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=2000005;
const int mod=998244353;
int t, n;
char ch[N];
int f(int x) {return ch[x]-'A'+1;}
int ksm(int x,int y) {
	int ans=1;
	while(y) {
		if(y%2==1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;	
	}
	return ans;
}
signed main() {
//	freopen("a.in","r",stdin);
//	freopen("my.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		scanf("%s", ch+1);
		int ans=0, x, y, touch=0;	
		if(n%2==1) {
			x=(n+1)/2-1, y=(n+1)/2+1;
			ans=f((n+1)/2);
			touch=1;
		} else {
			x=n/2-1, y=n/2+2;
			if(f(n/2)<=f(n/2+1)) ans=f(n/2);
			else if(f(n/2)>f(n/2+1)) ans=f(n/2)-1;
			if(f(n/2)==f(n/2+1)) touch=1;
		}
		int lev=1;
//		cout<<"ans="<<ans<<'\n';
		while(x>=1) {
			lev++;
			if(f(x)<f(y)) {
				int s1=ksm(26,lev-1)*(f(x)-1)%mod;
				ans=(s1+ans)%mod;
				touch=0;
			} else if(f(x)==f(y)) {
				int s1=ksm(26,lev-1)*(f(x)-1)%mod;
				ans=(s1+ans)%mod; //right
			} else if(f(x)>f(y)) {
				int s1=ksm(26,lev-1)*(f(x)-1)%mod;
				ans=(s1+ans-touch+mod)%mod;
				touch=0;
			}
//			cout<<"ans="<<ans<<'\n';
			x--, y++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

