#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=400005;
int q,a[N],st,ed,opt,x;
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
	return x*f;
}
void write(int x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
signed main() {
	st=1,ed=0;
	q=read();
	while(q--) {
		opt=read();
		if(opt==1) {
			x=read();
			a[++ed]=x;
		} else if(opt==2) {
			write(a[st]);
			puts("");
			st++;
		} else if(opt==3) {
			sort(a+st,a+ed+1); 
		}
	}
	return 0;
}

