#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
const int N=200005;
int x, y, n;
signed main() {
    cin>>x>>y>>n;
    if(1.0*x<1.0*y/3) cout<<n*x;
    else cout<<y*(n/3)+x*(n%3);
    return 0;
}