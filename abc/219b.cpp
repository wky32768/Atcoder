#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
char a[55],b[55],c[55],ans[1005];
int n,cnt;
signed main() {
	cin>>a>>b>>c;
	scanf("%s",ans+1);
	for(int i=1;i<=strlen(ans+1);i++) {
		if(ans[i]=='1') cout<<a;
		else if(ans[i]=='2') cout<<b;
		else if(ans[i]=='3') cout<<c;
	}
	return 0;
}

