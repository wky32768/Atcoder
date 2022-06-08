#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long 
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
int n, l, sum, ans;
int a[N];
priority_queue <int, vector <int>, greater<int> > q;
signed main() {
    cin>>n>>l;
    For(i,1,n) {
        cin>>a[i];
        sum+=a[i];
        q.push(a[i]);
    }
    if(l-sum>0) q.push(l-sum);
    For(i, 1, (l-sum>0?n:n-1)) {
        int fi=q.top(); q.pop();
        int se=q.top(); q.pop();
        ans+=(fi+se);
        q.push(fi+se);
    }
    cout<<ans<<'\n';
    return 0;
}