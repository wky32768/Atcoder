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

int h, w, a[105][105];

signed main() {
    cin >> h >> w;
    For(i, 1, h) For(j, 1, w) cin >> a[i][j];
    For(i, 1, h) {
        For(j, 1, w) {
            if(!a[i][j]) cout  << ".";
            else cout << (char)(a[i][j] + 'A' - 1);
        }
        cout << endl;
    }
    return 0;
}