#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,h[200005];
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	int now=1;
	while(now<=n-1 && h[now]<h[now+1]) now++;
	cout<<h[now];
	return 0;
}
