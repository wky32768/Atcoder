#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n, l, r, a[N], suml[N], sumr[N];
signed main() {
    cin>>n>>l>>r;
    For(i,1,n) cin>>a[i];
    For(i,1,n) suml[i]=min(suml[i-1]+a[i], l*i);
    for(int i=n;i>=1;i--) sumr[i]=min(sumr[i+1]+a[i], r*(n-i+1));
    // For(i,1,n) cout<<suml[i]<<" "; puts("");
    // For(i,1,n) cout<<sumr[i]<<" "; puts("");
    int ans=1e18;
    For(i,0,n) ans=min(ans, suml[i]+sumr[i+1]);
    cout<<ans<<'\n';
    return 0;
}