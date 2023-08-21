#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
const int N = 10005;
vector <int> e[N];
int n, m, a[N], at[N], inn[N];
void dfs(int now, int which) {
    // cout << "debug " << now << " " << which << '\n';
    at[now] = which;
    if(e[now].empty()) return;
    For(i, 0, e[now].size() - 1) {
        // cout << "search " << e[now][i] << '\n';
        if(!at[e[now][i]]) dfs(e[now][i], which);
    }
}
signed main() {
    cin >> n;
    For(i, 1, n) {
        cin >> m;
        For(j, 1, m) {
            cin >> a[j];
            inn[a[j]] = 1;
        }
        For(j, 2, m) {
            e[a[1]].push_back(a[j]);
            e[a[j]].push_back(a[1]);
        }
    }
    int tot = 0, totat = 0;
    For(i, 1, 10000) if(inn[i]) tot++;
    For(i, 1, 10000)
        if(inn[i] && !at[i])
            dfs(i, ++totat);
    cout << tot << " " << totat << '\n';
    int q; cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        if(at[x] == at[y]) cout << "Y\n";
        else cout <<"N\n";
    }


    return 0;
}