#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=300005;
int n,k,a[N],tot[N],ans;
map <int,int> mp;
signed main() {
	cin>>n>>k;
	For(i,1,n) {
		cin>>a[i];
		tot[i]=tot[i-1]+a[i];
	}
	mp[0]=1;
	For(i,1,n) {
		ans=ans+mp[tot[i]-k];
		mp[tot[i]]++;	
	}
	cout<<ans;
	return 0;
}
