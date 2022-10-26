#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n,sz[N][6];
int f[N][6]; //时间为i, 位置为j, 最多抓了多少
signed main() {
    cin>>n;
    For(i,1,n) {
        int x, y, z; cin>>x>>y>>z;
        sz[x][y]=z;
    }
    For(i,1,5) f[0][i]=-1e18;
    f[0][0]=0;
    For(i,1,100000) 
        For(j,0,4) {
            f[i][j]=f[i-1][j]+sz[i][j];
            if(j-1>=0) f[i][j]=max(f[i][j], f[i-1][j-1]+sz[i][j]);
            if(j+1<=4) f[i][j]=max(f[i][j], f[i-1][j+1]+sz[i][j]);
        }
    int ans=0;
    For(i,0,4) ans=max(ans,f[100000][i]);
    cout<<ans<<'\n';
}