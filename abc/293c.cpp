#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 200005;

int h, w, a[15][15], ans;
map <int, int> times;

void dfs(int x, int y) {
    if(x == h && y == w) {
        ans ++;
        return;
    }
    if(x + 1 <= h) {
        if(times[a[x + 1][y]] != 1) {
            times[a[x + 1][y]] = 1;
            dfs(x + 1, y);
            times[a[x + 1][y]] = 0;
        }
    }
    if(y + 1 <= w) {
        if(times[a[x][y + 1]]!= 1) {
            times[a[x][y + 1]] = 1;
            dfs(x, y + 1);
            times[a[x][y + 1]] = 0;
        }
    }
}

signed main() {
    cin >> h >> w;
    For(i, 1, h) For(j, 1, w) cin >> a[i][j];
    times[a[1][1]] = 1;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}