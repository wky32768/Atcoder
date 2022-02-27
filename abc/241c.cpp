#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++) 
using namespace std;
struct node {
	char ch[1005];
} a[1005];
int n,sum[2005][1005];
signed main() {
	cin>>n;
	For(i,1,n) {
		scanf("%s", a[i].ch+1);
		For(j,1,n) sum[i][j]=sum[i][j-1]+(a[i].ch[j]=='#');
		For(j,1,n-5) if(sum[i][j+5]-sum[i][j-1]>=4) {puts("Yes"); return 0;}
	}
	memset(sum, 0, sizeof sum);
	//先列后行
	For(i,1,n) {
		For(j,1,n) sum[i][j]=sum[i][j-1]+(a[j].ch[i]=='#');
		For(j,1,n-5) if(sum[i][j+5]-sum[i][j-1]>=4) {puts("Yes"); return 0;}
	}
	
	memset(sum, 0, sizeof sum);
	For(i,1,2*n-1) {
		if(i<=n) {
			For(j,1,i) sum[i][j]=sum[i][j-1]+(a[j].ch[i+1-j]=='#');
			For(j,1,i-5) if(sum[i][j+5]-sum[i][j-1]>=4) {puts("Yes"); return 0;}
		} else {
			For(j,1,2*n-i) sum[i][j]=sum[i][j-1]+(a[i-n+j].ch[i+1-(i-n+j)]=='#');
			For(j,1,2*n-i-5) if(sum[i][j+5]-sum[i][j-1]>=4) {puts("Yes"); return 0;}
		}
	}
	
	
	memset(sum, 0, sizeof sum);
	For(i,1,2*n-1) {
		if(i<=n) {
			int ed=n+1-i,tot=0;
			for(int j=1;ed<=n;j++,ed++) {tot++; sum[i][j]=sum[i][j-1]+(a[j].ch[ed]=='#');}
			For(j,1,tot-5) if(sum[i][j+5]-sum[i][j-1]>=4) {puts("Yes"); return 0;}
		} else {
			int st=i-n+1,tot=0;
			for(int j=1;st<=n;j++,st++) {tot++; sum[i][j]=sum[i][j-1]+(a[st].ch[j]=='#');}
			For(j,1,tot-5) if(sum[i][j+5]-sum[i][j-1]>=4) {puts("Yes"); return 0;}
		}
	}
	
	puts("No");
	return 0;
}

