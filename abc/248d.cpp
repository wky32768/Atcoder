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
int n, q, l, r, x;
int a[N];
vector <int> mp[N];
signed main() {
    cin>>n;
    For(i,1,n) {
        cin>>a[i];
        mp[a[i]].push_back(i);
    }
    cin>>q;
    while(q--) {
        cin>>l>>r>>x;
        cout<<lower_bound(mp[x].begin(),mp[x].end(),r+1)-lower_bound(mp[x].begin(),mp[x].end(),l)<<'\n';
    }
    return 0;
}