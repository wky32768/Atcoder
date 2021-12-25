#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int n,c,sum[120005],x;
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>c;
		sum[i]=sum[i-1]+c;
	}
	cin>>x;
	int a=x/sum[n],b=0;
	for(int i=1;i<=n;i++) {
		if(sum[i]<=x%sum[n]) b=i;
	}	
	cout<<a*n+b+1;
	return 0;
}

