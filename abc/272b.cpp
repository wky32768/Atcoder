#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
const int N=105;
int n, m, a[N][N];
signed main() {
    cin >> n >> m;
    For(i, 1, m) {
        int k; cin >> k;
        For(j, 1, k) {
            int x; cin >> x;
            a[x][++a[x][0]] = i;
        }
    }
    For(i, 1, n) For(j, i+1, n) {
        bool ok=0;
        For(k, 1, a[i][0]) For(l, 1, a[j][0]) {
            if(a[i][k] == a[j][l]) {ok=1; break;}
        }
        if(ok==0) {puts("No"); return 0;}
    }
    puts("Yes");
    return 0;
}