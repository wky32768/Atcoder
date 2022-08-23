#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=205;
int h1, w1, h2, w2, a[N][N], b[N][N], ans1[N], ans2[N];
void dfs2(int x, int at) {
    if(x>w2) {
        bool ok=1;
        // puts("debug :");
        // For(i,1,h2) cout<<ans1[i]<<" ";
        // puts("");
        // For(i,1,w2) cout<<ans2[i]<<" ";
        // puts("");
        For(i,1,h2) For(j,1,w2)
            if(a[ans1[i]][ans2[j]]!=b[i][j]) {
                ok=0;break;
            }
        if(ok==1) {puts("Yes"); exit(0);}
        return;
    }
    ans2[x]=at;
    if(at+1<=w1+1) dfs2(x+1, at+1);
    ans2[x]=0;
    if(at+1<=w1+1) dfs2(x, at+1);
    return;
}
void dfs1(int x, int at) {
    if(x>h2) {
        dfs2(1, 1);
        return;
    }
    ans1[x]=at;
    if(at+1<=h1+1) dfs1(x+1, at+1);
    ans1[x]=0;
    if(at+1<=h1+1) dfs1(x, at+1);
    return;
}
signed main() {
    cin>>h1>>w1;
    For(i,1,h1) For(j,1,w1) cin>>a[i][j];
    cin>>h2>>w2;
    For(i,1,h2) For(j,1,w2) cin>>b[i][j];
    dfs1(1, 1);
    puts("No");
    return 0;
}