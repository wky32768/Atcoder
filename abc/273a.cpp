#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i, a, b) for(int i = a; i <= b; i ++)
using namespace std;
int f[15], n;
signed main() {
    f[0]=1;
    For(i,1,10) f[i]=f[i-1]*i;
    cin>>n;
    cout<<f[n];
    return 0;
}