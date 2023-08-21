#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
const int N = 100005;
int pr[N], tot[N];
signed main() {
    pr[1] = 0;
    pr[2] = 1;
    For(i, 2, 100000) pr[i] = 1;
    For(i, 2, 100000) if(pr[i] == 1) {
        for(int j = 2;i * j <= 100000;j ++)
            pr[i * j] = 0;
    }
    For(i, 1, 100000) tot[i] = tot[i - 1] + pr[i];
    int n;
    while(cin >> n) {
        cout << tot[n] << '\n';
    }
    return 0;
}