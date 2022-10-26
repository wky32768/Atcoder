#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n;
double ans;
signed main() {
    cin>>n;
    ans=3.5;
    For(i,2,n) {
        double ans2=0;
        For(j,1,6) ans2+=1.0/6*max(j*1.0,ans);
        ans=ans2;
    }
    printf("%.10lf", ans);
    return 0;
}