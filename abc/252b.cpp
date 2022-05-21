#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int n, k, mx, x;
int a[N], inn[N];
signed main() {
    cin>>n>>k;
    For(i,1,n) {
        cin>>a[i];
        mx=max(mx,a[i]);
    }    
    For(i,1,n) if(a[i]==mx) inn[i]=1;
    while(k--) {
        cin>>x;
        if(inn[x]==1) {puts("Yes"); return 0;}
    }
    puts("No");
    return 0;
}