#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i, a, b) for(int i = a; i <= b; i ++)
#define int long long
using namespace std;
int x, k;
signed main() {
    cin>>x>>k;
    int ans=x;
    For(i,1,k) {
        int kk=pow(10,i);
        int ans1=x/kk*kk, ans2=(x/kk+1)*kk;
        ans=(abs(ans-ans1)<abs(ans-ans2)?ans1:ans2);
        // cout<<"debug "<<ans1<<" "<<ans2<<" "<<ans<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}