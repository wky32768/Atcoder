#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=10005;
int n, a[N], b[N], ans1, ans2;
signed main() {
	cin>>n;
	For(i,1,n) cin>>a[i];
	For(i,1,n) cin>>b[i];
	For(i,1,n) For(j,1,n) if(a[i]==b[j]) {
		if(i==j) ans1++;
		else ans2++;	
	}
	cout<<ans1<<'\n'<<ans2;
	return 0;
}

