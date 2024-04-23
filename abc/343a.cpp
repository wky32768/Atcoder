#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int N = 1e5 + 5;

int a, b;


signed main() {
    cin >> a >> b;
    for(int i = 0;i <= 9;i ++)
        if(i != a + b) {
            cout << i;
            break;
        }
    return 0;
}