#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
#define mp make_pair

using namespace std;

const int N = 1e3 + 5;

int h, w, dis[N][N];
char ch[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue <pair <int, int> > q;
bool vis[N][N];


using namespace std;
signed main() {
    cin >> h >> w;
    For(i, 1, h) For(j, 1, w) dis[i][j] = 1e9;

    For(i, 1, h) {
        scanf("%s", ch[i] + 1);
        For(j, 1, w) {
            if(ch[i][j] == 'E') {
                q.push(mp(i, j));
                dis[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        pair <int, int> u = q.front();
        q.pop();
        int x = u.first, y = u.second;
        For(i, 0, 3) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || nx > h || ny < 1 || ny > w || vis[nx][ny] || ch[nx][ny] == '#')
                continue;
            vis[nx][ny] = 1;
            dis[nx][ny] = dis[x][y] + 1;
            q.push(mp(nx, ny));
        }
    }

    For(i, 1, h) {
        For(j, 1, w) {
            if(ch[i][j] == 'E')
                cout << "E";
            else if(i - 1 >= 1 && dis[i - 1][j] == dis[i][j] - 1) 
                cout << "^";
            else if(i + 1 <= h && dis[i + 1][j] == dis[i][j] - 1)
                cout << "v";
            else if(j - 1 >= 1 && dis[i][j - 1] == dis[i][j] - 1)
                cout << "<";
            else if(j + 1 <= w && dis[i][j + 1] == dis[i][j] - 1)
                cout << ">";
            else
                cout << ch[i][j];
        }
        cout << endl;
    }




    return 0;
}
