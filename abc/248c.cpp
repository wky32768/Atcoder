#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int mod=998244353;
int n, m, k;
int f[105][3005]; //考虑前i个数, 当前总和为j
signed main() {
    cin>>n>>m>>k;
    f[0][0]=1;
    For(i,1,n)
        For(now, 0, k)
            For(j,1,m)
                if(j+now<=k)
                    f[i][j+now]=(f[i][j+now]+f[i-1][now])%mod;
    int ans=0;
    For(i,n,k) ans=(ans+f[n][i])%mod;
    cout<<ans<<'\n';
    return 0;
}