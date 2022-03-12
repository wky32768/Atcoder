#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n, a, b, c;
signed main() {
	cin>>n>>a>>b>>c;
	n%=(a+b+c);
	if(n<a) puts("F");
	else if(n<a+b) puts("M");
	else puts("T");
	return 0;
}

