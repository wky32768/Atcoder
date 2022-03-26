#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n, a, x;
map <int, int> mp;
signed main() {
    cin>>n;
    For(i,1,n) {
        cin>>x;
        mp[x]++;
    }
    For(i,0,2000) if(mp[i]==0) {cout<<i; return 0;}
}