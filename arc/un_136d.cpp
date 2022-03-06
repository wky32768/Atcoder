#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++) 
using namespace std;
const int N=1100005;
int n, ans, c[N], a[N][7], temp[N], calc[N];
signed main() {
	cin>>n;
	For(i,1,n) cin>>c[i];
	For(i,1,n) {
		int cnt=0;
		while(c[i]) {
			temp[++cnt]=c[i]%10;
			c[i]/=10;
		}
		For(j,1,cnt) a[i][j]=temp[j];
	}
	int ans=0;
	For(i,0,63) {
//		cout<<"i="<<i<<'\n';
		int tot=0; //ÓÐ¼¸¸ö1 
		memset(calc, 0, sizeof calc);
		For(j,1,6) {
			int at=(i>>(j-1))%2;
//			cout<<"at="<<at<<'\n';
			if(at==1) tot++;
		}	 
		if(tot==0) continue;
		For(j,1,n) {
			int now=0;
			For(k,1,6) {
				int at=(i>>(k-1))%2;
				if(at==1) now=now*10+a[j][k];
			}
//			cout<<"now="<<now<<'\n';
			calc[now]++;
		}
		int need=(tot==1)?10:11*(int)pow(10,tot-1);
		int temp_sum=0,at_mid=calc[need/2];
		for(int j=need;j>=0;j--) calc[j]=calc[j+1]+calc[j];
//		puts("debug_calc");
//		For(j,0,need) cout<<calc[j]<<" ";
//		puts("");
		For(j,1,need/2-1)  {
			temp_sum+=(calc[j]-calc[j+1])*calc[need-j];
//			if((calc[j]-calc[j+1])*calc[need-j]!=0) {
//				cout<<"added at"<<j<<'\n';	
//			}
		}
//		cout<<"at_mid="<<at_mid<<'\n';
		temp_sum+=(at_mid)*(at_mid-1);
//		cout<<"temp_sum="<<temp_sum<<'\n';
		if(tot%2==1) ans+=temp_sum;
		else ans-=temp_sum;
	}
	cout<<n*(n-1)/2-ans<<'\n';
}

