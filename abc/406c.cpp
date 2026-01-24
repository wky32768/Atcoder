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

const int N = 3e5 + 5;

int h, w, n, now;
struct rub {
    int x, y;
} a[N];
set <int> r[N], c[N];


using namespace std;
signed main() {
    cin >> h >> w >> n;
    For(i, 1, n) {
        cin >> a[i].x >> a[i].y;
        r[a[i].x].insert(i);
        c[a[i].y].insert(i);
    }
    int q;
    cin >> q;
    while(q--) {
        int opt; cin >> opt >> now;
        if(opt == 1) {
            cout << r[now].size() << '\n';
            for(auto i : r[now]) c[a[i].y].erase(i);
            r[now].clear();
        } else {
            cout << c[now].size() << '\n';
            for(auto i : c[now]) r[a[i].x].erase(i);
            c[now].clear();
        }
    }

    return 0;
}
