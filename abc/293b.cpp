#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 200005;

int n, a[N], called[N];

signed main() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) {
        if(called[i] == 0) {
            called[a[i]] = 1;
        }
    }
    int tot = 0;
    For(i, 1, n) if(!called[i]) tot ++;
    cout << tot << endl;
    For(i, 1, n) if(!called[i]) cout << i << " ";
    return 0;
}