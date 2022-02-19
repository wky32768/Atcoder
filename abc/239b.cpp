#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int x;
signed main() {
	cin>>x;
	if(x>=0) cout<<x/10;
	else {
		x=-x;
		if(x%10==0) cout<<"-"<<x/10;
		else cout<<"-"<<x/10+1;	
	}
	return 0;
}

