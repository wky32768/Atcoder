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

int a, x, m;

struct mat {
    int c[5][5];
};

mat mul(mat aa, mat bb) {
    mat cc;
    For(i, 1, 2) For(j, 1, 2) cc.c[i][j] = 0;
    For(i, 1, 2)
        For(j, 1, 2)
            For(k, 1, 2)
                cc.c[i][j] = (cc.c[i][j] + aa.c[i][k] * bb.c[k][j]) % m;
    return cc;
}

mat ksm(mat x, int n) {
    mat ans;
    For(i, 1, 2) For(j, 1, 2) ans.c[i][j] = (i == j ? 1 : 0);
    while(n) {
        if(n & 1) ans = mul(ans, x);
        x = mul(x, x);
        n >>= 1;
    }
    return ans;
}

signed main() {
    cin >> a >> x >> m;
    mat start;
    For(i, 1, 2) For(j, 1, 2) start.c[i][j] = 0;
    start.c[2][1] = 1;
    mat temp;
    For(i, 1, 2) For(j, 1, 2) temp.c[i][j] = 0;
    temp.c[1][1] = a;
    temp.c[1][2] = 1;
    temp.c[2][2] = 1;
    mat ans = mul(ksm(temp, x), start);
    cout << ans.c[1][1] << endl;
    return 0;
}