#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
int n;
signed main() {
    cin >> n;
    int now = 1;
    For(i, 1, 30) {
        now *= i;
        if(now == n) {
            cout << i;
            return 0;
        }
    }
    return 0;
}