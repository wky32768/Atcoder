#include <bits/stdc++.h>
#include <cstdio>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
const int N = 200005;
int n, fa[N], isfa[N], bf[N], mx;
vector <int> v[N];
void dfs(int x) {
    if(fa[x] == -1) bf[x] = 1;
    else bf[x] = bf[fa[x]] + 1;
    mx = max(mx, bf[x]);
    for(int i = 0;i < v[x].size(); i++) {
        dfs(v[x][i]);
    }
}
signed main() {
    cin >> n;
    For(i, 1, n) {
        cin >> fa[i];
        if(fa[i] > 0) isfa[fa[i]] = 1;
        v[fa[i]].push_back(i);
    }
    For(i, 1, n) if(fa[i] == -1) dfs(i);
    cout << mx << '\n';
    int first = 0;
    For(i, 1, n) if(bf[i] == mx) {
        if(first == 0) first = 1;
        else cout << " ";
        cout << i;
    }


    return 0;
}