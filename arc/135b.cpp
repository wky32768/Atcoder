#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i, a, b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
const int N=600005;
int n, a[N], b[N], ans[N];
signed main() {
	cin>>n;
	For(i, 1, n) cin>>a[i];
	//n+2:Êý×Ö×ÜÊý 
	for(int i=1;i+3<=n+2;i++) b[i]=a[i+1]-a[i];
	int now=0,mn1=0;
	for(int i=1;i+3<=n+2;i+=3) {
		now=now+b[i];
//		cout<<"now="<<now<<'\n';
		mn1=min(mn1, now);
	}
	now=0;
	int mn2=0;
	for(int i=2;i+3<=n+2;i+=3) {
		now=now+b[i];
		mn2=min(mn2, now);	
	}
	now=0;
	int mn3=0;
	for(int i=3;i+3<=n+2;i+=3) {
		now=now+b[i];
		mn3=min(mn3, now);	
	}
	if((-1)*(mn1+mn2+mn3)>a[1]) puts("No");
	else {
		ans[1]=-mn1+(a[1]-(-1)*(mn1+mn2+mn3)), ans[2]=-mn2, ans[3]=-mn3;
		for(int i=4;i<=n+2;i++) ans[i]=ans[i-3]+b[i-3];
		puts("Yes");
		for(int i=1;i<=n+2;i++) cout<<ans[i]<<" ";
	}
	return 0;
}

