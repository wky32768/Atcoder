#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n;

signed main() {
    cin >> n;
    For(i, 0, n - 1) {
        cout << char(i + 'A');
    }
    return 0;
}