#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int a, b, c, d, e, f, x;
signed main() {
    cin>>b>>a>>c>>e>>d>>f>>x;
    int dis1=x/(b+c)*(a*b)+min(b, x%(b+c))*a;
    int dis2=x/(e+f)*(d*e)+min(e, x%(e+f))*d;
    // cout<<"debug "<<dis1<<" "<<dis2<<'\n';
    if(dis1>dis2) puts("Takahashi");
    else if(dis1<dis2) puts("Aoki");
    else puts("Draw");
    return 0;
}