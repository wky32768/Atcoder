#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
#define mp make_pair

using namespace std;

const int N = 21;

int h, w;
int a[N][N], ans;
bool vis[N][N];

void dfs(int x, int y, int now) {
    // cout << "debug dfs: " << x << " " << y << " " << now << endl;
    if(x == h && y > w) {
        ans = max(ans, now);
        return;
    }
    if(y > w) {
        dfs(x + 1, 1, now);
        return;
    }
    if(vis[x][y]) {
        dfs(x, y + 1, now);
        return;
    }
    if(vis[x][y] == 0 && vis[x][y + 1] == 0 && y + 1 <= w) {
        vis[x][y] = vis[x][y + 1] = 1;
        dfs(x, y + 1, now ^ a[x][y] ^ a[x][y + 1]);
        vis[x][y] = vis[x][y + 1] = 0;
    }
    if(vis[x][y] == 0 && vis[x + 1][y] == 0 && x + 1 <= h) {
        vis[x][y] = vis[x + 1][y] = 1;
        dfs(x, y + 1, now ^ a[x][y] ^ a[x + 1][y]);
        vis[x][y] = vis[x + 1][y] = 0;

    }
    dfs(x, y + 1, now);
    return;
}

using namespace std;
signed main() {

    cin >> h >> w;
    int noww = 0;
    For(i, 1, h) For(j, 1, w) {
        cin >> a[i][j];
        noww = noww ^ a[i][j];
    }
    dfs(1, 1, noww);
    cout << ans << endl;

    return 0;
}
