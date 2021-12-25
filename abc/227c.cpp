#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n;
signed main() {
	cin>>n;
	int tot=0;
	for(int i=1;i*i*i<=n;i++) 
		for(int j=i;i*j*j<=n;j++)
			tot+=n/i/j-j+1;
	cout<<tot;
	return 0;
}
