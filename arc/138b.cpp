#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=400005;
int n, a[N], b[N], len, c, l, r;
int find(int x) {
	return (a[x]+c)%2;
}
bool q() {
	return find(l)==0;	
}
bool h() {
	return find(r)==0;
}
signed main() {
	cin>>n;
	For(i,1,n) cin>>a[i];
	l=1, r=n;
	while(l<=r && (q() || h())) {
		if(h()) {r--;continue;}
		if(!q()) {puts("No"); return 0;}
		if(q()) {
			l++; c++;
		}
	}
	if(l<=r) puts("No");
	else puts("Yes");
	return 0;
}
