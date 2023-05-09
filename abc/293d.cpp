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
const int N = 500005;

// 1 ~ n: red
// n + 1 ~ 2n: blue

int n, m, x, y, tot_cycle, tot_noncycle;
int connect[N << 1], vis[N];
char s1, s2;

int at(int now) {
    return (now <= n ? now : now - n);
}

void dfs(int now) {
    // cout << "Dfs " << now << '\n';
    int which = at(now);
    vis[which] = 1;
    int op = (now <= n ? now + n : now - n);
    // cout << "op? " << op << " " << connect[op] << '\n';
    if(!connect[op]) {tot_noncycle ++; return;}
    if(vis[at(connect[op])]) {tot_cycle ++; return;}
    dfs(connect[op]);
}


signed main() {
    cin >> n >> m;
    For(i, 1, m) {
        cin >> x >> s1 >> y >> s2;
        int now_x = (s1 == 'R' ? x : x + n);
        int now_y = (s2 == 'R' ? y : y + n);
        // cout << "debug " << now_x << " " << now_y << '\n';
        connect[now_x] = now_y;
        connect[now_y] = now_x;
    }
    For(i, 1, n * 2) {
        if(!vis[at(i)] && !connect[i]) dfs(i);
        if(!vis[at(i)] && !connect[i + n]) dfs(i + n);
    }
    For(i, 1, n * 2) {
        if(!vis[at(i)]) dfs(i);
    }

    cout << tot_cycle << " " << tot_noncycle << endl;

    return 0;
}