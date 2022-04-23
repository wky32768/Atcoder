#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=305;
int n, k, ans;
int x[N], y[N];
bool counted[N][N];
vector <int> lst;
int same_line(int a,int b,int c) {
    return (x[c]-x[b])*(y[a]-y[b])==(y[c]-y[b])*(x[a]-x[b]);
}
signed main() {
    cin>>n>>k;
    if(k==1) {puts("Infinity"); return 0;}
    For(i,1,n) cin>>x[i]>>y[i];
    For(i,1,n) For(j,i+1,n) if(!counted[i][j]) {
        int tot=2;
        lst.clear(); lst.push_back(i); lst.push_back(j);
        For(kk,j+1,n) if(same_line(i,j,kk)) {
            tot++; lst.push_back(kk);
        }
        For(ii,0,lst.size()-1) For(jj,ii+1,lst.size()-1)
            counted[lst[ii]][lst[jj]]=1;
        if(tot>=k) ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
