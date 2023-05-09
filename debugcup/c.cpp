#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for(int i = a; i <= b;i ++)
using namespace std;
int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}

void write(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) write(x / 10);
    putchar('0' + x % 10);
    return;
}

const int N = 30000;
int t, head[N], cnt;
struct node {
    int next, to;
} sxd[N];

void add(int u, int v) {
    sxd[++cnt].next=head[u];
    sxd[cnt].to = v;
    head[u] = cnt;
}

bool vis[N];

void dfs(int at) {
    vis[at] = 1;
    for(int i = head[at];i;i=sxd[i].next){
        if(!vis[sxd[i].to]) dfs(sxd[i].to);
    }
}


signed main() {
    t = read();
    while(t--) {
        memset(head, 0, sizeof head);
        cnt = 0;
        int n, m;
        cin >> n >> m;
        For(i, 1, m) {
            int u = read(), v = read();
            add(u, v); add(v, u);
        }
        if(m != n - 1) {
            puts("no");
        } else {
            memset(vis, 0, sizeof vis);
            dfs(1);
            bool ok = 1;
            For(i, 1, n) if(!vis[i]) ok = 0;
            if(ok == 1) puts("yes");
            else puts("no");
        }
    }
    return 0;
    
}