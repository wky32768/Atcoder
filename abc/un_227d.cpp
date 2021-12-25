#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=220005;
int n,k,t[N];
priority_queue <int> q;
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
signed main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		q.push(read());
	}
	int ans=0;
	while(q.size()>=k) {
		int cnt=0;
		For(i,1,k) {
			t[++cnt]=q.top();
			q.pop();
		}
		ans++;
		For(i,1,k) if(t[i]-1>0) q.push(t[i]-1);
	}
	cout<<ans;
	return 0;
}
