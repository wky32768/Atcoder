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
    int temp=n%998244353ll;
    if(temp<0) temp+=998244353;
    cout<<temp<<'\n';
    return 0;
}