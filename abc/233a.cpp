#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int x,y;
signed main() {
	cin>>x>>y;
	if(x>=y) {puts("0"); return 0;}
	cout<<max(0,(y-x-1)/10+1);
	return 0;

}

