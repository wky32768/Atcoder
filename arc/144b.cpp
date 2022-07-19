#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=300005;
int n, A, B, a[N];
bool ok(int x) {
    int jia=0, jian=0;
    For(i,1,n) {
        if(a[i]<x) jia+=(x-a[i]-1)/A+1;
        else jian+=(a[i]-x)/B;
    }
    return jia<=jian;
}
signed main() {
    cin>>n>>A>>B;
    For(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    int l=a[1], r=a[n], ans=0;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(ok(mid)) {
            ans=mid; l=mid+1;
        } else r=mid-1;
    }
    cout<<ans<<'\n';
    return 0;
}