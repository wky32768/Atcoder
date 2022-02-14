#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i, a, b) for(int i=a;i<=b;i++)
using namespace std;
const int N=300005;
int n, a[N], b[N];
signed main() {
	cin>>n;
	For(i, 1, n) cin>>a[i];
	sort(a+1, a+n+1);
	int mx=0;
	while((1<<mx)<=a[n]) mx++;
//	cout<<"mx="<<mx<<'\n';
	for(int i=mx-1;i>=0;i--) {
		int tot_zero=0;
		For(j, 1, n) if((a[j]>>i)%2==0) tot_zero++;
		int tot_one=n-tot_zero;
//		cout<<i<<" "<<tot_zero<<" "<<tot_one<<'\n';
//		if(tot_one==1) {
//			int at=0;	
//			For(j, 1, n) if((a[j]>>i)%2==1) {at=j; break;}
//			int temp=a[at], ans=0;
//			For(j, 1, n) a[j]=a[j]^temp;
//			For(j, 1, n) ans+=a[j];
//			cout<<ans;
//			return 0;
//		} else 
		if(tot_one<n) {
			if(tot_zero>=tot_one) {
				int at=0,mn=1e18;
				for(int j=n;j>=1;j--) if((a[j]>>i)%2==1 && (a[j]>>(i+1))%2==0 && a[j]<mn) {at=j;mn=a[j];}
				if(at) {
					int temp=a[at];
					For(j, 1, n) a[j]=a[j]^temp;
				}
			}
		}
//		For(j,1,n) cout<<a[j]<<" ";
//		puts("");
	}	

	int ans=0;
	For(i, 1, n) {
//		cout<<a[i]<<" ";
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}

