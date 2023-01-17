#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int a, b;

signed main() {
    cin >> a >> b;
    if(b == a * 2 || b == a * 2 + 1) puts("Yes");
    else puts("No");
    return 0;
}