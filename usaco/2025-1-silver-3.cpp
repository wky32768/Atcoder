#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long
using namespace std;

const int N = 2010;

int n, a[N][N], ans1[N][N], ans2[N][N], trans[N], times[N], used[N];

bool les() {
    For(i, 1, n) For(j, 1, n)
        if(trans[a[i][j]] != 2 * n + 2 - trans[a[i][j]])
            return trans[a[i][j]] < 2 * n + 2 -trans[a[i][j]];
}

signed main() {
    cin >> n;
    For(i, 1, n) For(j, 1, n) {
        cin >> a[i][j];
        times[a[i][j]] ++;
    }
    int atx = 0, aty = 0;
    For(i, 1, n) For(j, 1, n) if(times[a[i][j]] == 1){
        atx = i, aty = j;
        trans[a[i][j]] = 2;
        break;
    }
    For(j, 1, n) {
        trans[a[atx][j]] = times[a[atx][j]] + 1; 
        used[a[atx][j]] = 1;
    }
    For(i, 2, n * 2) {
        if(!used[i]) 
            trans[i] = 2 * n + 2 - (times[i] + 1);
    }
    if(les() == 0) {
        For(i, 2, 2 * n) trans[i] = 2 * n + 2 - trans[i];
    }
    For(i, 1, n) {
        For(j, 1, n)
            cout << trans[a[i][j]] << " ";
        puts("");
    }
    return 0;
}