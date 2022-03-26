#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=205;
int n, m;
int a[N], b[N], c[N];
signed main() {
    cin>>n>>m;
    For(i,0,n) cin>>a[i];
    For(i,0,n+m) cin>>c[i];
    int now=n+m+1;
    for(int i=m;i>=0;i--) {// 要计算的b值
        now--; //now是目前c的值
        int tot=0, x=0;
        for(int j=0;j<=n;j++) for(int k=0;k<=m;k++) if(j+k==now) {
            if(k==i) x=a[j];
            else tot+=a[j]*b[k];
        }
        // cerr<<"debug "<<c[now]<<" "<<tot<<" "<<x<<'\n';
        b[i]=(c[now]-tot)/x;
    }
    For(i,0,m) cout<<b[i]<<" ";
    return 0;
}