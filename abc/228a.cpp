#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int a,b,c;
signed main() {
	cin>>a>>b>>c;
	if(a<b) {
		if(a<=c && c<b) puts("Yes");
		else puts("No");	
	} else {
		if(c>=a || c<b) puts("Yes");
		else puts("No");	
	}
	return 0;
}
