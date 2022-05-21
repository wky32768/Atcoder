#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n, ans, mx, a[N];
map <int, int> mp;
signed main() {
    cin>>n;
    For(i,1,n) {
        cin>>a[i];
        mp[a[i]]++;
        mx=max(mx, a[i]);
    }
    For(i,1,mx) if(mp[i]) {
        For(j,1,sqrt(i)) if(i%j==0) if(mp[j] && mp[i/j]) {
            // ans+=mp[i]*mp[j]*mp[i/j]*2;
            if(i==j && j==1/j) ans+=mp[i]*mp[j]*mp[i/j];
            else if(j==1) ans+=mp[j]*mp[i]*mp[i]*2;
            else if(j==i/j) ans+=mp[i]*mp[j]*mp[j];
            else ans+=mp[i]*mp[j]*mp[i/j]*2;
            // cout<<i<<" "<<j<<" "<<i/j<<" "<<ans<<'\n';
        }
    }
    cout<<ans<<'\n';
    return 0;
}