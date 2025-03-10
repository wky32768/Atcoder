#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 3e5 + 10;
int n, a[N], sum[N], cnt, fro;
signed main() {
    cin >> n;
    while(n --) {
        int opt; cin >> opt;
        if(opt == 1) {
            int x; cin >> x;
            a[++cnt] = x;
            sum[cnt] = sum[cnt - 1] + x;
        } else if(opt == 2) {
            fro ++;
        } else {
            int x; cin >> x;
            cout << sum[fro + x - 1] - sum[fro] << endl;
        }
    }
    return 0;
}