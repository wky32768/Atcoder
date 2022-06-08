#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int n, a[105][105];
signed main() {
    cin>>n;
    a[1][1]=1;
    For(i,2,n) {
        For(j,1,i) a[i][j]=a[i-1][j]+a[i-1][j-1];
    }
    For(i,1,n) {
        For(j,1,i) cout<<a[i][j]<<" ";
        puts("");
    }
    return 0;
}