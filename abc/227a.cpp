#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,a;
signed main() {
	cin>>n>>k>>a;
	int now=a;
	for(int i=1;i<=k-1;i++) {
		now=now%n+1;
	}
	cout<<now;
	return 0;
}

