#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int n,m,x,y,a[N][9];
signed main() {
	cin>>n>>m;
	For(i,1,n) For(j,1,m) cin>>a[i][j];
	For(i,1,n) For(j,1,m) {
		if(i==1 && j==1) continue;
		if(j==1) {
			if(a[i-1][1]+7!=a[i][j]) {puts("No");return 0;}
		} else {
			if((a[i][j]-1)%7+1!=(a[i][j-1]-1)%7+2) {puts("No");return 0;}
		}
	}
	puts("Yes");
	return 0;
}
