#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int x, y;
int gcd(int x,int y) {
    if(x<y) swap(x, y);
    return x%y==0?y:gcd(y, x%y);
}
signed main() {
    cin>>x>>y;
    int ans=y-x;
    while(1) {
        bool flag=false;
        for(int i=x;i+ans<=y;i++) {
            int j=i+ans;
            if(gcd(i,j)==1) {flag=1; break;}
        }
        if(flag==1) {cout<<ans; return 0;}
        ans--;
    }
    return 0;
}