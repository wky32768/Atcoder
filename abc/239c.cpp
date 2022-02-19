#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define int long long
using namespace std;
int a,b,c,d;
map <pair <int, int>,int> q;
signed main() {
	cin>>a>>b>>c>>d;
	q[make_pair(a-1,b-2)]=1;
	q[make_pair(a-1,b+2)]=1;
	q[make_pair(a-2,b-1)]=1;
	q[make_pair(a-2,b+1)]=1;
	q[make_pair(a+1,b-2)]=1;
	q[make_pair(a+1,b+2)]=1;
	q[make_pair(a+2,b-1)]=1;
	q[make_pair(a+2,b+1)]=1;
	if(q[make_pair(c-1,d-2)]==1) {puts("Yes"); return 0;}
	if(q[make_pair(c-1,d+2)]==1) {puts("Yes"); return 0;}
	if(q[make_pair(c-2,d-1)]==1) {puts("Yes"); return 0;}
	if(q[make_pair(c-2,d+1)]==1) {puts("Yes"); return 0;}
	if(q[make_pair(c+1,d-2)]==1) {puts("Yes"); return 0;}
	if(q[make_pair(c+1,d+2)]==1) {puts("Yes"); return 0;}
	if(q[make_pair(c+2,d-1)]==1) {puts("Yes"); return 0;}
	if(q[make_pair(c+2,d+1)]==1) {puts("Yes"); return 0;}
	puts("No");
	return 0;
}

