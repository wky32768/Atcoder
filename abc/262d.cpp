#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=105;
const int mod=998244353;
int n, ans, a[N], f[N][N][N]; //前i个中选了j个, %mo=k
signed main() {
    cin>>n; For(i,1,n) cin>>a[i];
    For(mo,1,n) {
        memset(f, 0, sizeof(f));
        f[0][0][0]=1;
        For(i,0,n-1) For(j,0,mo) For(k,0,mo-1) {
            f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k])%mod;
            if(j+1<=mo) f[i+1][j+1][(k+a[i+1])%mo]=(f[i+1][j+1][(k+a[i+1])%mo]+f[i][j][k])%mod;
        }
        ans=(ans+f[n][mo][0])%mod;
    }
    cout<<ans<<'\n';
    return 0;
}