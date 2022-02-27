#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++) 
using namespace std;
int a[10];
signed main() {
	For(i,0,9) cin>>a[i];
	int now=0;
	For(i,1,3) now=a[now];
	cout<<now<<'\n';
	return 0;

}

