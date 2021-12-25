#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100005;
int n,x,y,a[N];
signed main() {
	cin>>n;
	for(int i=1;i<=n-1;i++) {
		cin>>x>>y;
		a[x]++,a[y]++;
	}
	for(int i=1;i<=n-1;i++) {
		if(a[x]==n-1 || a[y]==n-1) {puts("Yes"); return 0;}	
	}
	puts("No");
}
