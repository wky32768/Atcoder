#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int a,b,c,d,ok[105];
bool is_prime(int x) {
	if(x==1) return 0;
	else if(x==2) return 1;
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;	
}
signed main() {
	cin>>a>>b>>c>>d;
	int x=0,y=0;
	for(int i=a;i<=b;i++) {
		for(int j=c;j<=d;j++) {
			if(is_prime(i+j)==1) ok[i]=1;	
		}
		if(ok[i]!=1) {puts("Takahashi"); return 0;}
	}
	puts("Aoki");
	return 0;
}

