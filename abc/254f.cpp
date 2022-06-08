#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=800005;
int a[N], b[N], temp[N], tree1[N], tree2[N];
int n, q;
//gcd
int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}
int make1(int rt, int l, int r) {
    if(l==r) {tree1[rt]=temp[l]; return temp[l];}
    int mid=(l+r)>>1;
    int lc=make1(rt<<1, l, mid);
    int rc=make1(rt<<1|1, mid+1, r);
    tree1[rt]=gcd(lc, rc);
    return tree1[rt];
}
int make2(int rt, int l, int r) {
    if(l==r) {tree2[rt]=temp[l]; return temp[l];}
    int mid=(l+r)>>1;
    int lc=make2(rt<<1, l, mid);
    int rc=make2(rt<<1|1, mid+1, r);
    tree2[rt]=gcd(lc, rc);
    return tree2[rt];
}
int search1(int rt, int l, int r, int L, int R) {
    if(L>r || R<l) return 0;
    if(L<=l && R>=r) return tree1[rt];
    int mid=(l+r)>>1;
    return gcd(search1(rt<<1, l, mid, L, R), search1(rt<<1|1, mid+1, r, L, R));
}
int search2(int rt, int l, int r, int L, int R) {
    if(L>r || R<l) return 0;
    if(L<=l && R>=r) return tree2[rt];
    int mid=(l+r)>>1;
    return gcd(search2(rt<<1, l, mid, L, R), search2(rt<<1|1, mid+1, r, L, R));
}
signed main() {
    cin>>n>>q;
    For(i,1,n) {cin>>a[i]; temp[i]=abs(a[i]-a[i-1]);}
    make1(1, 1, n);
    For(i,1,n) {cin>>b[i]; temp[i]=abs(b[i]-b[i-1]);}
    make2(1, 1, n);
    while(q--) {
        int h1, h2, w1, w2;
        cin>>h1>>h2>>w1>>w2;
        int ans=a[h1]+b[w1];
        if(h2!=h1) ans=gcd(ans, search1(1, 1, n, h1+1, h2));
        if(w2!=w1) ans=gcd(ans, search2(1, 1, n, w1+1, w2));
        cout<<ans<<endl;
    }
    return 0;
}
