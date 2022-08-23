#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n, a[N];
bool cmp(int x, int y) {return x>y;}
bool cmp2(int x, int y) {
    vector <int> a1, a2;
    while(x) {a1.push_back(x%10); x/=10;}
    while(y) {a2.push_back(y%10); y/=10;}
    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());
    For(i,0,min(a1.size(), a2.size())-1)
        if(a1[i]!=a2[i]) return a1[i]>a2[i];
}
signed main() {
    cin>>n;
    For(i,1,n) cin>>a[i];
    sort(a+1,a+n+1, cmp);
    sort(a+1,a+3+1, cmp2);
    For(i,1,3) cout<<a[i];
    return 0;
}