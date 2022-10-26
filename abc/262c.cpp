#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=500005;
int n, a[N], same, ans;
signed main() {
    cin>>n;
    For(i,1,n) {
        cin>>a[i];
        if(a[i]==i) same++;
    }
    For(i,1,n) if(a[i]!=i && a[a[i]]==i) ans++;
    ans=ans/2+same*(same-1)/2;
    cout<<ans<<'\n';
    return 0;
}