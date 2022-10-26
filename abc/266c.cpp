#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int a[5][3];
void test(int aa, int bb,int cc) {
    int x=a[aa][1]-a[bb][1],y=a[aa][2]-a[bb][2],z=a[cc][1]-a[bb][1],w=a[cc][2]-a[bb][2];
    if(z*y-x*w<=0) {puts("No"); exit(0);}
}
signed main() {
    For(i,1,4) For(j,1,2) cin>>a[i][j];
    test(1,2,3); test(2,3,4); test(3,4,1); test(4,1,2);
    puts("Yes");
}