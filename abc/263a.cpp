#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int a[6];
signed main() {
    For(i,1,5) cin>>a[i];
    sort(a+1, a+5+1);
    cout<<(((a[1]==a[3] && a[4]==a[5]) || (a[1]==a[2] && a[3]==a[5])) ? "Yes" : "No");
    return 0;
}