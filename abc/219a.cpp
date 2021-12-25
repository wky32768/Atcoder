#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n; 
signed main() {
	cin>>n;
	if(n>=90)  puts("expert");
	else if(n>=70) cout<<90-n;
	else if(n>=40) cout<<70-n;
	else cout<<40-n;
	return 0;
}

