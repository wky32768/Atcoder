#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=400005;
int n, k, f[N][21], llog2[N];
struct node {
	int num, id;
	friend bool operator < (node a, node b) {
		return a.num<b.num;
	}
} a[N];
int search(int l,int r) {
	int s=llog2[r-l+1];
	return max(f[l][s], f[r-(1<<s)+1][s]);
}
int find(int cd) {
	int l=1, r=k, ans=0;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(a[mid].num<cd) {//manzu
			ans=mid; l=mid+1;
		} else r=mid-1;
	}
	return ans;
}
signed main() {
	cin>>n>>k;
	For(i,1,n) {cin>>a[i].num; a[i].id=i;}
	sort(a+1, a+k+1);
	For(i,1,n) f[i][0]=a[i].id;
	For(i,1,20) for(int j=1;j+(1<<i)-1<=n;j++)
		f[j][i]=max(f[j][i-1], f[j+(1<<(i-1))][i-1]);
	For(i,2,n) llog2[i]=llog2[i/2]+1;
	int ans=0x3f3f3f3f;
	For(i,k+1,n) {
		int p=find(a[i].num);
//		cout<<"p="<<p<<'\n';
		if(p==0) continue;
		ans=min(ans, i-search(1,p));
	}
	if(ans<=n) cout<<ans;
	else cout<<"-1";
	return 0;
}
