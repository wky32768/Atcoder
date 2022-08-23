#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=2005;
int n, m, cnt, ans[N], a[N][N];
void dfs(int at, int x) {
    if(at>n) {
        cnt++;
        For(i,1,n) a[cnt][i]=ans[i];
        return;
    }
    if(x+1<=m+1) dfs(at, x+1);
    ans[at]=x;
    if(x+1<=m+1) dfs(at+1, x+1);
    ans[at]=0; 
}
signed main() {
    cin>>n>>m;
    dfs(1, 1);
    for(int i=cnt;i>=1;i--) {
        For(j,1,n) cout<<a[i][j]<<" ";
        puts("");
    }
    return 0;
}