#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
 
using namespace std;

const int N = 255005;
int n, m, cnt, head[N << 1];
int a[N], ans;
int fa[N];

struct node {
    int next, to, w;
} sxd[N];

struct Line {
    int x, y, w;
    friend bool operator < (Line a, Line b) {
        return a.w > b.w;
    }
} lines[N];

int ksm(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = (ans * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return ans;
}

void add(int x, int y, int w) {
    sxd[++cnt].next = head[x];
    sxd[cnt].to = y;
    sxd[cnt].w = w;
    head[x] = cnt;
}

int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void kruskal() {
    For(i, 1, n) fa[i] = i;
    sort(lines + 1, lines + n * (n - 1) / 2 + 1);
    For(i, 1, n * (n - 1) / 2) {
        int xx = lines[i].x, yy = lines[i].y;
        // cout << "debug1 " << xx << " " << yy << '\n';
        int find_x = find(xx), find_y = find(yy);
        if(find_x == find_y) continue;
        // cout << "debug2 " << xx << " " << yy << '\n';
        ans += lines[i].w;
        fa[find_x] = find_y;
    }
}

signed main() {
    cin >> n >> m;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) For(j, i + 1, n) {
        int x = (int)(ksm(a[i], a[j]) + ksm(a[j], a[i])) % m;
        add(i, j, x);
        lines[++lines[0].x] = (Line) {i, j, x};
        // cout << i << " " << j << " " << x << '\n';
    }
    kruskal();
    cout << ans;
    return 0;
} 