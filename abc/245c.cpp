#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n, k, a[N], b[N], ok[N][3];//现在第i位, 上一个是j
signed main() {
    cin>>n>>k;
    For(i,1,n) cin>>a[i];
    For(i,1,n) cin>>b[i];
    ok[1][1]=ok[1][2]=1;
    For(i,2,n) {
        if(abs(a[i]-b[i-1])<=k) 
            ok[i][1]=max(ok[i][1], ok[i-1][2]);
        if(abs(b[i]-b[i-1])<=k)
            ok[i][2]=max(ok[i][2], ok[i-1][2]);
        if(abs(a[i]-a[i-1])<=k)
            ok[i][1]=max(ok[i][1], ok[i-1][1]);
        if(abs(b[i]-a[i-1])<=k)
            ok[i][2]=max(ok[i][2], ok[i-1][1]);
    }
    puts(max(ok[n][1], ok[n][2])>=1?"Yes":"No");
    return 0;
}