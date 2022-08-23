#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
const int N=200005;
int n, m, t, x, y;
int a[N], bo[N];
signed main() {
    cin>>n>>m>>t; t+=bo[1];
    For(i,1,n-1) cin>>a[i];
    For(i,1,m) {
        cin>>x>>y;
        bo[x]=y;
    }
    int at=1;
    while(at<n  && t) {
        if(t-a[at]<=0) break;
        t-=a[at]; at++; t+=bo[at];
    }
    puts(at==n?"Yes":"No");
    return 0;
}