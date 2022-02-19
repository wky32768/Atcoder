#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
double ans;
signed main() {
	int h;
	cin>>h;
	h=h*(12800000+h);
	printf("%.6lf",sqrt(h));
	return 0;
}

