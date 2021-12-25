#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
char ch[1000005];
int ans[1000005],tot[1000005];
signed main() {
	scanf("%s",ch+1);
	int n=strlen(ch+1);
	For(i,1,n) tot[i]=tot[i-1]+ch[i]-'0';
	For(i,1,n) {
		ans[i]+=tot[n+1-i];
//		cout<<i<<" "<<ans[i]<<'\n';
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;	
//		cout<<i<<" "<<ans[i]<<'\n';
	}
	int len=(ans[n+1]==0?n:n+1);
//	cout<<ans[5]<<'\n';
//	while(ans[len]>=10){
//		ans[len+1]+=ans[len]/10;
//		ans[len]%=10;
//		len++;	
//	}
//	cout<<"len="<<len<<'\n';
	for(int i=len;i>=1;i--) cout<<ans[i];
	return 0;
}
