#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n, fa[N];
signed main() {
    cin>>n;
    For(i,2,n) cin>>fa[i];
    int now=n, tot=0;
    while(fa[now]!=1) {
        tot++;
        now=fa[now];
    }
    cout<<tot+1<<endl;
    return 0;
}