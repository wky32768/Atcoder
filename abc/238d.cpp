#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
using namespace std;
int t,a,n,mn,mx;
int pw[120];
bool ok;
signed main() {
	cin>>t;
	pw[0]=1;
	for(int i=1;i<=60;i++) pw[i]=pw[i-1]*2;
	while(t--) {
		cin>>a>>n;
		mn=mx=0;
		for(int i=0;i<=60;i++) {
			if((a>>i)%2==0) {
			} else {
				n-=pw[i]*2;
				if(n<0) {puts("No"); goto L1;}
			}
		}
		ok=0;
//		cout<<"n="<<n<<'\n';
		for(int i=60;i>=0;i--) if((a>>i)%2==0) {
			if(n>=pw[i]) n-=pw[i];
//			cout<<i<<" "<<" n="<<n<<'\n';
			if(n==0) ok=1;
		}
		if(ok) puts("Yes");
		else puts("No");
		L1:;
	}
	return 0;
}

