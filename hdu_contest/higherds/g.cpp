#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
const int N = 300005;
int n, q, c[N];
struct route {
    int x, y, mnn;
    friend bool operator < (route a, route b) {
        if(a.y != b.y) return a.y < b.y;
        else return a.x < b.x;
        // if(a.x != b.x) return a.x < b.x;
        // else return a.y < b.y;
    }
} r[N];
// st table to save the minimum
int mn[N][21];
int query(int l,int r) {
    int k=log2(r-l+1);
    return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int f[N];
signed main() {
    cin >> n >> q;
    For(i, 1, n - 1) {
        cin >> c[i];
        mn[i][0] = c[i];   
    }
    for(int j=1; j<=21; j++)
        for(int i=1; i+(1<<j)-1<=n; i++)
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]); 
    For(i, 1, q) {
        cin >> r[i].x >> r[i].y;
        if(r[i].x > r[i].y) swap(r[i].x, r[i].y);
        r[i].mnn = query(r[i].x + 1, r[i].y);
        // cout << "Debug " << r[i].x << " " << r[i].y << " " << r[i].mnn << '\n';
    }
    For(i, q + 1, q + n) {
        r[i] = (route) {i-(q+1), i-q, 0};
    }
    q = q + n + 1;
    sort(r + 1, r + q + 1);
    For(i, 1, q) {
        f[r[i].y] = max(f[r[i].y], f[r[i].x] + r[i].mnn);
        // cout << "Debug " << r[i].y << " " << f[r[i].y] << '\n';
    }
    For(i, 1, q) {
        f[r[i].y] = max(f[r[i].y], f[r[i].x] + r[i].mnn);
        // cout << "Debug " << r[i].y << " " << f[r[i].y] << '\n';
    }
    int mx = 0;
    For(i, 1, n) mx = max(mx, f[i]);
    cout << mx << '\n';


    return 0;
}