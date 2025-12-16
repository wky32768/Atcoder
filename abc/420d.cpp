#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;


const int N = 505;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

char a[N][N];
int dis[N][N][2];

queue <pair <pair <int, int>, int> > q;

int h, w;

signed main() {
    cin >> h >> w;
    int stx = 0, sty = 0, edx = 0, edy = 0;
    For(i, 1, h) {
        scanf("%s", a[i] + 1);
        For(j, 1, w) {
            if(a[i][j] == 'S') {
                stx = i;
                sty = j;
            } else if(a[i][j] == 'G') {
                edx = i;
                edy = j;
            }
        }
    }
    memset(dis, -1, sizeof dis);

    dis[stx][sty][0] = 0;
    q.push({{stx, sty}, 0});
    while(!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second, now = q.front().second;
        q.pop();
        if(x == edx && y == edy) {
            cout << dis[x][y][now] << endl;
            return 0;
        }
        For(i, 0, 3) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || nx > h || ny < 1 || ny > w) continue;
            if(a[nx][ny] == '#') continue;
            if(now == 1 && a[nx][ny] == 'o') continue;
            if(now == 0 && a[nx][ny] == 'x') continue;
            
            if(a[nx][ny] == '?') {
                if(dis[nx][ny][1 - now] >= 0) continue;
                dis[nx][ny][1 - now] = dis[x][y][now] + 1;
                q.push({{nx, ny}, 1 - now});
            } else {
                if(dis[nx][ny][now] >=0 ) continue;
                dis[nx][ny][now] = dis[x][y][now] + 1;
                q.push({{nx, ny}, now});
            }
        }

    }
    cout << -1 << endl;

    return 0;
}