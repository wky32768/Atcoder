#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int t, n, a[N];
// bool ok(int x) {
//     int tot=0, mx_first=0, mx_second=0;
//     For(i,1,n) {

//     }
// }
signed main() {
    cin>>t;
    while(t--) {
        cin>>n>>m;
        For(i,1,n) cin>>a[i];
        int sum=0;
        For(i,1,n) sum+=a[i];
        // int l=0,r=sum,ans=0;
        // while(l<=r) {
        //     int mid=(l+r)>>1;
        //     if(ok(mid)) ans=mid, r=mid-1;
        //     else l=mid+1;
        // }
        // cout<<ans<<'\n';
    }
    return 0;
}