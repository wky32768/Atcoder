#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
struct node {
    int aa[105][105];
    int h, w;
} a, b;
node mul(node a, node b) {
    node c;
    c.h = a.h; c.w = b.w;
    For(i, 1, c.h) For(j, 1, c.w) c.aa[i][j] = 0;
    For(i, 1 ,a.h) For(j, 1, a.w) For(k, 1, b.w) {
        c.aa[i][k] += a.aa[i][j] * b.aa[j][k];
        // c.aa[i][k] %= mod;
    }
    return c;
}
signed main() {
    cin >> a.h >> a.w;
    For(i, 1, a.h) For(j, 1, a.w) cin >> a.aa[i][j];
    cin >> b.h >> b.w;
    For(i, 1, b.h) For(j, 1, b.w) cin >> b.aa[i][j];
    if(a.w != b.h) {
        cout << "Error: " << a.w << " != " << b.h << '\n';
        return 0;
    }
    node c = mul(a, b);
    cout << c.h << " " << c.w << '\n';
    For(i, 1, c.h) {
        For(j, 1, c.w) {
            cout << c.aa[i][j];
            if(j != c.w) cout << " ";
        }
        puts("");
    }
    return 0;
}