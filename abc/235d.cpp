#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
int a,n,ans[1000005];
queue <int> q;
signed main() {
	cin>>a>>n;
	q.push(1);
	while(!q.empty()) {
		int now=q.front();
		q.pop();
//		cout<<"now:"<<now<<" "<<ans[now]<<'\n';
		int b=now*a;
		if(b>1000000) goto L1;
//		cout<<"b="<<b<<'\n';
		if(ans[b]==0) {
			ans[b]=ans[now]+1;
//			cout<<"ans[b]="<<ans[b]<<'\n';
			if(b==n) {
				cout<<ans[n];
				return 0;	
			}
			q.push(b);
		}
		L1:;
		int ws=0,temp=now;
		if(now<=10 || now%10==0) goto L2;
		while(temp) {temp/=10;ws++;}
		b=now/10+now%10*pow(10,ws-1);
		if(b>1000000) goto L2;
//		cout<<"b="<<b<<'\n';
		if(ans[b]==0) {
			ans[b]=ans[now]+1;
//			cout<<"ans[b]="<<ans[b]<<'\n';
			if(b==n) {
				cout<<ans[n];
				return 0;
			}
			q.push(b);
		}
		L2:;
	}
	puts("-1");
}
