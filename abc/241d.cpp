#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++) 
using namespace std;
multiset <int> s;
int q, opt, x, k;
signed main() {
	cin>>q;
	while(q--) {
		scanf("%lld", &opt);
		if(opt==1) {
			scanf("%lld", &x);
			s.insert(x);
		} else if(opt==2) { //小中取大 
			scanf("%lld%lld", &x, &k);
			multiset <int> :: iterator it=s.upper_bound(x);
			For(i,1,k) {
				if(it==s.begin()) {puts("-1"); goto L1;}
				it--;
			}
			printf("%lld\n", *it);
		} else if(opt==3) { 
			scanf("%lld%lld", &x, &k);
			multiset <int> :: iterator it=s.lower_bound(x);
			if(it==s.end()) {puts("-1"); goto L1;}
			For(i,1,k-1) {
				it++;
				if(it==s.end()) {puts("-1"); goto L1;}
			}
			printf("%lld\n", *it);
		}
		L1:;
	}
	return 0;
}
	
