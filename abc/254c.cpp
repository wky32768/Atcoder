#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=300005;
int n, k, a[N], b[N], c[N], d[N], cnt1, cnt2;
signed main() {
    cin>>n>>k;
    For(i,1,n) {cin>>a[i]; b[i]=a[i];}
    sort(b+1, b+n+1);
    For(i,1,k) {
        cnt1=cnt2=0;
        for(int j=i;j<=n;j+=k) {c[++cnt1]=a[j]; d[++cnt2]=b[j];}
        sort(c+1, c+cnt1+1); sort(d+1, d+cnt2+1);
        for(int j=1;j<=cnt1;j++) {
            // cout<<c[j]<<" "<<d[j]<<'\n';
            if(c[j]!=d[j]) {puts("No"); return 0;}
        }
    }
    puts("Yes"); return 0;
}