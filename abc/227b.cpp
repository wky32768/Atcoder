#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=25;
int n,s[N];
bool flag[10005];
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=1000;i++) for(int j=1;j<=1000;j++) 
		if(4*i*j+3*i+3*j<=2000) flag[4*i*j+3*i+3*j]=1;
	int tot=0;
	for(int i=1;i<=n;i++) if(flag[s[i]]) {
		cout<<"1";
		tot++;	
	} else {cout<<"0";}
	cout<<n-tot;
	return 0;
}
