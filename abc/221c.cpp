#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define int long long
int n,a[105],cnt,x,y;
bool cmp(int a,int b) {return a>b;}
signed main() {
	cin>>n;
	while(n) {a[++cnt]=n%10; n/=10;}
	sort(a+1,a+cnt+1,cmp);
	x=a[1],y=a[2];
	if(x==y) {
		int now=3;
		while(a[now]==a[now+1] && now+1<=cnt) {
			x=x*10+a[now];
			y=y*10+a[now+1];	
			now+=2;
		}
		if(now==cnt) {x=x*10+a[now];goto L1;}
		if(now>cnt) {goto L1;}
		x=x*10+a[now];
		y=y*10+a[now+1];
		if(cnt%2==0) {
			for(int i=now+2;i<=cnt;i++) {
				if(i%2==1) y=y*10+a[i];
				else x=x*10+a[i];
			}
		} else {
			for(int i=now+2;i<=cnt-1;i++) {
				if(i%2==1) y=y*10+a[i];
				else x=x*10+a[i];
			}
			y=y*10+a[cnt];	
		}
	} else {
		if(cnt%2==0) {
			for(int i=3;i<=cnt;i++) {
				if(i%2==1) y=y*10+a[i];
				else x=x*10+a[i];	
			}
		} else {
			for(int i=3;i<=cnt-1;i++) {
				if(i%2==1) y=y*10+a[i];
				else x=x*10+a[i];
			}
			y=y*10+a[cnt];
		}		
	}
	L1:;
	cout<<x*y<<'\n';
}

