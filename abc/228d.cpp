#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N=1200005;
int q,t,x;
int a[N],nxt_f1[N];
signed main() {
	cin>>q;
	int c=pow(2,20);
//	cout<<c<<'\n';
	for(int i=0;i<=c-2;i++) {
		nxt_f1[i]=i+1;
		a[i]=-1;
	}
	nxt_f1[c-1]=0;
	a[c-1]=-1;
	while(q--) {
		cin>>t>>x;	
		if(t==1) {
			if(a[x%c]==-1) {
				a[x%c]=x;
//				cout<<"debug "<<x%c<<" "<<x<<'\n';
			} else {
				int haha=nxt_f1[x%c];
				while(a[haha]!=-1) haha=nxt_f1[haha];
				a[haha]=x;
				nxt_f1[x%c]=nxt_f1[haha];
//				cout<<"Debug "<<nxt_f1[x%c]<<" "<<x<<'\n';
			}
		} else if(t==2) {
//			cout<<"??? "<<x%c<<'\n';
			cout<<a[x%c]<<'\n';	
		}	
	}
}

