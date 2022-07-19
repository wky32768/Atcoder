#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n;
signed main() {
    cin>>n;
    cout<<n*2<<'\n';
    if(n%4) {cout<<n%4; n-=n%4;}
    For(i,1,n/4) cout<<"4";
    return 0;
}