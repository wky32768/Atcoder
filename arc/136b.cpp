#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++) 
using namespace std;
const int N=200005;
int n, a[N], b[N], c[N], d[N], same=0;
signed main() {
	cin>>n;
	For(i,1,n) {cin>>a[i]; c[i]=a[i];}
	For(i,1,n) {cin>>b[i]; d[i]=b[i];}
	sort(c+1, c+n+1); sort(d+1, d+n+1);
	For(i,1,n) {
		if(c[i]!=d[i]) {puts("No"); return 0;}
		if(c[i]==c[i+1]) same=1;
	}
	if(same==1) {puts("Yes"); return 0;}
	int ni1=0, ni2=0;
	For(i,1,n) For(j,i+1,n) if(a[i]>a[j]) ni1++;
	For(i,1,n) For(j,i+1,n) if(b[i]>b[j]) ni2++;
	if(ni1<ni2) swap(ni1, ni2);
	if((ni1-ni2)%2==0) puts("Yes");
	else puts("No");
	return 0;
}

