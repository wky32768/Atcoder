#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++) 
using namespace std;
map <int,int> mp;
int n,m,x;
signed main() {
	cin>>n>>m;
	For(i,1,n) {
		cin>>x;
		mp[x]++;
	}
	For(i,1,m) {
		cin>>x;
		if(mp[x]<1) {puts("No");return 0;}	
		else mp[x]--;
	}
	puts("Yes");
	return 0;
}

