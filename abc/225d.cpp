#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int n,q,opt,x,y,ans[N],cnt;
struct node {
	int n,nxt,fro;
} a[N];
int read() {
	int f=1,x=0;
	char ch=getchar();
	while(!(ch>='0' && ch<='9')) { 
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();	
	}
	return f*x;
}
void write(int x) {
	if(x<0) {putchar('-'); x=-x;}
	if(x>=10) write(x/10);
	putchar(x%10+'0');	
}
signed main() {
	cin>>n>>q;
	For(i,1,q) {
		opt=read();
		if(opt==1) {
			x=read(),y=read();
			a[x].nxt=y;		
			a[y].fro=x;
		} else if(opt==2) {
			x=read(),y=read();
			a[x].nxt=0;
			a[y].fro=0;
		} else if(opt==3) {
			x=read();
			while(a[x].fro) x=a[x].fro;
			ans[1]=x;
			cnt=1;
			while(a[x].nxt) {
				ans[++cnt]=a[x].nxt;
				x=a[x].nxt;	
			}
			cout<<cnt<<" ";
			For(j,1,cnt)  {
				write(ans[j]);
				putchar(' ');	
			}
			puts("");
		}
	}
	return 0;
}

