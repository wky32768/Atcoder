#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n, m, k, a[N];
bool cmp(int x, int y) {return x>y;}
int dig[N][33], all_zero[N];
struct node {
    int cost, id;
    friend bool operator < (node a, node b) {
        return a.cost < b.cost;
    }
} cd[N];
int at(int x, int y) {
    return (x>>y)&1;
}
signed main() {
    cin>>n>>m>>k;
    For(i,1,n) cin>>a[i];
    sort(a+1, a+n+1, cmp);
    int sum=0, ans=0;
    for(int i=30;i>=0;i--) {
        int need=0, cnt=0;
        For(j,1,n) {
            if(a[j]<=ans+(1<<i)) cd[++cnt]=(node) {ans+(1<<i)-a[j], j};
            else {
                int wky=0, add=0;
                for(int tt=30;tt>=0;tt--)
                    if(at(a[j], tt)==0 && at(ans+(1<<i), tt)==1) wky+=(1<<tt), add=1;
                    else if(at(a[j], tt)==1 && at(ans+(1<<i), tt)==0 && add==1) wky-=(1<<tt);
                cd[++cnt]=(node) {wky, j};
            }
        }
        sort(cd+1, cd+cnt+1);
        For(j,1,k) need+=cd[j].cost;
        // cout<<"debug "<<i<<" "<<sum<<" "<<need<<" "<<cd[1].cost<<" "<<cd[2].cost<<" "<<cd[3].cost<<endl;
        if(sum+need<=m) {
            sum+=need, ans+=(1<<i);
            For(j,1,k) a[cd[j].id]+=cd[j].cost;
        }
    }
    cout<<ans<<'\n';
    return 0;
}