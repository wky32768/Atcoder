#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
const int N = 100005;
int n, m;
char c[25][25];
int used[25][25];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans;
void dfs(int x, int y) {
    // cout << "debug " << x << " " << y << '\n';
    used[x][y] = 1;
    For(i, 0, 3) {
        int xx = x + dx[i], yy = y + dy[i];
        if(xx <= 0 || xx > n  || yy <= 0 || yy > m)
            continue;
        if(c[xx][yy] == '#') continue;
        if(used[xx][yy]) continue;
        dfs(xx, yy);
    }
    return;
}
signed main() {
    while(cin >> n >> m) {
        if(!n && !m) break;
        swap(n, m);
        ans = 0;
        For(i, 1, n) scanf("%s", c[i] + 1);
        memset(used, 0, sizeof used);
        For(i, 1, n) For(j, 1, m) if(c[i][j] == '@') {
            dfs(i, j);
        }
        For(i, 1, n) For(j, 1, m) if(used[i][j]) ans++;
        cout << ans << '\n';
    }
    return 0;
}