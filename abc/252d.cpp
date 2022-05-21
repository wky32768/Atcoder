#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
#define int long long
const int N=200005;
int n, a[N], s[N], sum[N];
bool cmp(int a, int b) {return a>b;}
signed main() {
    cin>>n;
    For(i,1,n) cin>>a[i];
    sort(a+1, a+n+1, cmp);
    int last=1, cnt=0;
    For(i,1,n) {
        if(i!=1 && a[i]!=a[i-1]) {
            s[++cnt]=i-last;
            last=i;
        }
    }
    s[++cnt]=n+1-last;
    sort(s+1, s+cnt+1, cmp);
    // For(i,1,cnt) cout<<s[i]<<" "; puts("");
    int ans=n*(n-1)*(n-2)/6;
    For(i,1,n) if(s[i]>=2) {
        ans-=s[i]*(s[i]-1)/2*(n-s[i]);
    }
    For(i,1,n) if(s[i]>=3) ans-=s[i]*(s[i]-1)*(s[i]-2)/6;
    cout<<ans;
    return 0;
}