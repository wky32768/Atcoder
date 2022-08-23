#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int r, c, a[25][25];
signed main() {
    cin>>r>>c;
    for(int i=1;i<=7;i+=2) {
        For(j,i,15-i+1) a[i][j]=a[j][i]=a[15-i+1][j]=a[j][15-i+1]=1;
    }
    cout<<(a[r][c]==1?"black":"white")<<'\n';
    return 0;
}