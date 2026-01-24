#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 15;

int n, m;
int a[N][N], nxt[N];



using namespace std;
signed main() {
    cin >> n >> m;
    For(i, 1, m) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    For(i, 1, n) nxt[i] = i;
    int ans = 0x3f3f3f3f;
    do {
        int tot = 0;
        bool ok = 1;
        For(i, 1, n) 
            if(nxt[i] == i || nxt[nxt[i]] == i) {
                ok = 0; break;
            }
        if(!ok) continue;
        For(i, 1, n)
            if(!a[i][nxt[i]]) tot ++;
        ans = min(ans, tot + (m - (n - tot)));


    } while(next_permutation(nxt + 1, nxt + n + 1));
    
    cout << ans;

    return 0;
}
