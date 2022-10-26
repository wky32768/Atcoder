#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n, sum, a[105];
signed main() {
    cin >> n;
    for(int i=1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}