#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>

#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long

const int N = 5e5 + 5;
using namespace std;

int n, m, x, y, a[N], head[N], cnt;
int ru[N], ans[N], anss[N];
queue <int> q;
struct node {
    int next, to;
} sxd[N];
void add(int u,int v) {
    sxd[++cnt]=(node) {head[u],v};
    head[u]=cnt;
}

signed main() {
    cin >> n >> m;
    For(i, 1, m) {
        cin >> x >> y;
        add(x, y);
        ru[y] ++;
    }
    int tot = 0;
    For(i, 1, n) if(!ru[i]) {
        q.push(i);
        tot ++;
    }
    if(tot >= 2) {
        puts("No");
        return 0;
    }
    while(!q.empty()) {
        int now = q.front(), temp = 0; q.pop();
        ans[++ans[0]] = now;
        for(int i=head[now]; i; i = sxd[i].next) {
            int to = sxd[i].to;
            ru[to] --;
            if(!ru[to]) {
                if(!temp) {temp = to; q.push(temp);}
                else {
                    puts("No");
                    return 0;
                }
            }
        }
    }  
    if(ans[0] != n) puts("No");
    else {
        puts("Yes");
        For(i, 1, n) anss[ans[i]] = i;
        For(i, 1, n) cout << anss[i] << " ";
    }
    return 0;
}