#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
using namespace std;
map <pair <int, int>, bool> conn;
int n, m, u, v, ans;
signed main() {
    cin>>n>>m;
    For(i,1,m) {
        cin>>u>>v;
        if(u>v) swap(u, v);
        conn[mp(u, v)]=1;
    }
    For(i,1,n) For(j,i+1,n) For(k,j+1,n)
        if(conn[mp(i,j)]==1 && conn[mp(j,k)]==1 && conn[mp(i,k)]==1) ans++;
    cout<<ans<<'\n';
    return 0;
}