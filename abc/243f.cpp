#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int mod=998244353;
const int N=55;
int n, m, kk, sum;
int w[N], fac[N], inv_fac[N], f[N][N][N]; 
//f[i][j][k]:前i个彩票选了j个种类, 抽了k次

int ksm(int x, int k) {
    int ans=1;
    while(k) {
        if(k%2==1) ans=(ans*x)%mod;
        x=(x*x)%mod; k>>=1;
    }
    return ans;
}

signed main() {
    cin>>n>>m>>kk;
    For(i,1,n) {cin>>w[i]; sum+=w[i];}
    For(i,1,n) w[i]=w[i]*ksm(sum, mod-2)%mod;

    fac[0]=1, inv_fac[0]=1;
    For(i,1,50) fac[i]=fac[i-1]*i%mod;
    inv_fac[50]=ksm(fac[50], mod-2);
    for(int i=49;i>=1;i--) inv_fac[i]=inv_fac[i+1]*(i+1)%mod;
    
    f[0][0][0]=1; //a:摸了a张第i个彩票
    For(i,0,n-1) For(j,0,m) For(k,0,kk) For(a, 0, kk-k) 
        f[i+1][j+(a!=0)][k+a]=(f[i+1][j+(a!=0)][k+a]+f[i][j][k]*ksm(w[i+1], a)%mod*inv_fac[a]%mod)%mod;
    cout<<f[n][m][kk]*fac[kk]%mod;
    return 0;
}