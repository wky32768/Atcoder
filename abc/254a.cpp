#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int n;
signed main() {
    cin>>n;
    cout<<(n/10)%10<<n%10<<'\n';
    return 0;
}