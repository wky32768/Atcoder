#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define int long long
const int mod=998244353;
map <int, int> ans;
int dfs(int x) {
	if(x<=4) return x;
	if(ans[x]>0) return ans[x];
	else {
		ans[x]=(dfs(x/2)*dfs((x+1)/2))%mod;
		return ans[x];
	}
}
signed main() {
	int x;
	cin>>x;
	cout<<dfs(x);
	return 0;
}
