#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char a[5]={'a','B','R','G','H'},b[6];
int use[5];
signed main() {
	for(int i=1;i<=3;i++) {
		scanf("%s",b+1);
		for(int j=1;j<=4;j++) if(a[j]==b[2]) use[j]=1; 	
	}
	for(int j=1;j<=4;j++) if(use[j]==0) cout<<"A"<<a[j]<<"C";
	return 0;
}

