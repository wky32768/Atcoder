#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 200005;
int a, b;

signed main() {
    cin >> a >> b;
    cout << (int)pow(a, b);
    return 0;
}