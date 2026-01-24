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

const int N = 1e3 + 5;

vector <pair <int, int> > v[N];
queue <pair<int, int> > q;

int n, m;
bool vis[N][N];


using namespace std;
signed main() {
    
    cin >> n >> m;
    For(i, 1, m) {
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back(make_pair(y, w));
    }

    q.push(mp(1, 0));
    vis[1][0] = 1;
    while(!q.empty()) {
        pair<int, int> now = q.front(); q.pop();
        int at = now.first, num = now.second;
        for(auto i : v[now.first]) {
            int to = i.first, w = i.second;
            if(!vis[to][num ^ w]) {
                vis[to][num ^ w] = 1;
                q.push(mp(to, num ^ w));
            }
        }
    }
    For(i, 0, 1023) if(vis[n][i]) {
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;


    return 0;
}
