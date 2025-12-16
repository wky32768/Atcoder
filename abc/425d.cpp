#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 5e5 + 5;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int h, w;
vector < vector <char> > s;
vector < pair <int, int> > q;

signed main() {
    cin >> h >> w;
    int dif = 1, tot = 0;
    For(i, 0, h - 1) {
        vector <char> t(w + 1);
        For(j, 0, w - 1) {
            cin >> t[j];
            if(t[j] == '#') {
                tot++;
                q.push_back({i, j});
            }
        }
        s.push_back(t);
    }
    if(!q.size()) {
        cout << 0 << endl;
        return 0;
    }
    // cout << "debug " << tot << endl;
    while(dif) {
        int old = tot;
        vector < pair <int, int> > newq;
        if(!q.size()) break;
        For(i, 0, q.size() - 1) {
            int x = q[i].first, y = q[i].second;
            For(j, 0, 3) {
                int nx = x + dx[j], ny = y + dy[j];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(s[nx][ny] == '#') continue;
                int black = 0;
                For(k, 0, 3) {
                    int nnx = nx + dx[k], nny = ny + dy[k];
                    if(nnx < 0 || nnx >= h || nny < 0 || nny >= w) continue;
                    // cout << "ddddebug " << nx << " " << ny << " " << nnx << " " << nny << " " << s[nnx][nny] << endl;
                    if(s[nnx][nny] == '#') black++;
                }
                // cout << "debug " << x << " " << y << " " << nx << " " << ny << " " << black << endl;
                if(black == 1) {
                    tot++;
                    newq.push_back({nx, ny});
                }
            }
        }
        if(newq.size()) {
            For(i, 0, newq.size() - 1) {
                s[newq[i].first][newq[i].second] = '#';
            } 
        }
        q = newq;
        dif = tot - old;
    }
    cout << tot << endl;
    
    return 0;
}