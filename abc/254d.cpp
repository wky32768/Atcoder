#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=300005;
int n, ans;
signed main() {
    cin>>n;
    for(int k=1;k<=n;k++) {
        bool ok=1;
        for(int i=2;i*i<=k;i++) if(k%(i*i)==0) {ok=0; break;}
        int temp=sqrt(n/k);
        if(ok==1) ans+=temp*temp;
        // cout<<"ans="<<ans<<'\n';

    }
    cout<<ans<<'\n';
    return 0;
}