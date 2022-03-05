#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int a, b, c, x;
signed main() {
	cin>>a>>b>>c>>x;
	if(x>b) {puts("0"); return 0;}
	else if(x<=a) {puts("1"); return 0;}
	else cout<<c*1.0/(b-a);
	return 0;
}

