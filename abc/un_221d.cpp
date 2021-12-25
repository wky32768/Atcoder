#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
const int N=300005;
int n,a[N],b[N],sum,ans[N],l;
bool cmp(int x,int y) {return x>y;}
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++)  {cin>>a[i]>>l;b[i]=a[i]+l-1;}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);
	for(int i=n;i>=1;i--) {
		if(b[i]-a[i]+1-sum<=0) {sum=a[i]-b[i]-1;}
		else {
//		cout<<"???"<<b[i]<<" "<<a[i]<<" "<<sum<<'\n';
		ans[i]=b[i]-a[i]+1-sum,sum=b[i]-a[i]+1;
//		cout<<"ans"<<i<<" "<<ans[i]<<'\n';}	
//		cout<<"Debug "<<i<<" "<<sum<<'\n';
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}

