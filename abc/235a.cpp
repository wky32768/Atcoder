#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int a[5],n;
signed main() {
	cin>>n;
	a[1]=n/100;
	a[2]=(n/10)%10;
	a[3]=n%10;
	cout<<(a[1]+a[2]+a[3])*111;
	return 0;
}

