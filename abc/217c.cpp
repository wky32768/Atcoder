#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=300005;
int n,a[N],b[N];
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	return 0;
}

