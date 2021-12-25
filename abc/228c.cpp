#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n,k;
struct node {
	int sum;
	int id;	
	friend bool operator < (node x,node y) {
		return x.sum>y.sum;
	}
} a[N];
bool ok[N];
signed main() {	
	cin>>n>>k;
	For(i,1,n) {
		int x,y,z;
		cin>>x>>y>>z;
//		For(j,1,3) cin>>a[i].p[i][j];
		a[i].sum=x+y+z;
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	int line=a[k].sum;
	For(i,1,n) if(a[i].sum+300>=line) ok[a[i].id]=1;
	int tot=0;
	For(i,1,n) 
		if(ok[i]) puts("Yes");
		else puts("No");
	return 0;
}
