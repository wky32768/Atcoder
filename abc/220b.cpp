#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int k;
char a[1005],b[1005],c[1005];
int x,y,ans;
signed main() {
	cin>>k;
	scanf("%s",a+1); scanf("%s",b+1);
	for(int i=1;i<=strlen(a+1);i++) {
		x*=k;
		x+=a[i]-'0';	
	}
	for(int i=1;i<=strlen(b+1);i++) {
		y*=k;
		y+=b[i]-'0';	
	}
	ans=x*y;
	cout<<ans;
	return 0;
}

