#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define For(i, a, b) for(int i = a; i <= b; i ++)
#define int long long
const int N=200005;
using namespace std;
int n, a[N], b[N], c[N], d[N];
map <int, int> rk;
signed main() {
    cin >> n;
    For(i, 1, n) {cin >> a[i]; b[i] = a[i];}
    sort(b + 1, b + n + 1);
    int cnt=0;
    For(i, 1, n) if(b[i] > b[i - 1]) rk[b[i]] = ++cnt;
    For(i,1,n) c[i]=cnt-rk[a[i]];
    For(i,1,n) d[c[i]]++;
    For(i,0,n-1) cout<<d[i]<<'\n';
    return 0;
}