#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
int a, b;
signed main() {
    cin >> a >> b;
    printf("%.3lf", 1.0 * b / a);
    return 0;
}