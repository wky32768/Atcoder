#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int mod=998244353;
int n, f[1000005][12]; //当前i位, 最后一位是j 
signed main() {
	cin>>n;
	For(i,1,9) f[1][i]=1;
	For(i,2,n) {
		For(j,1,9) {
			if(j-1>=1) f[i][j-1]=(f[i][j-1]+f[i-1][j])%mod;
			if(j+1<=9) f[i][j+1]=(f[i][j+1]+f[i-1][j])%mod;
			f[i][j]=(f[i][j]+f[i-1][j])%mod;
		}
	}
	int tot=0;
	For(i,1,9) tot=(tot+f[n][i])%mod;
	cout<<tot;
	return 0;
}

