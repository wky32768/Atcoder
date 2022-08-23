#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
const int N=200005;
int n, p, q, r, sum, output;
int a[N];
set <int> s;
signed main() {
    cin>>n>>p>>q>>r;
    For(i,0,n-1) {
        cin>>a[i];
        sum+=a[i];
        s.insert(sum);
    }
    sum=0;
    For(i,-1,n-1) {
        if(i!=-1) sum+=a[i];
        if(s.find(sum+p)!=s.end() && s.find(sum+p+q)!=s.end() && s.find(sum+p+q+r)!=s.end()) {
            puts("Yes"); output=1; break;
        }
    }
    if(!output) puts("No");
    return 0;
}