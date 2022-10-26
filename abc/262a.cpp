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
    if(n%4<=2) cout<<n+2-n%4;
    else cout<<n+6-n%4;
    return 0;
}