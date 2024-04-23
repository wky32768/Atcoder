#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int N = 1e5 + 5;

char ch[N];

signed main() {
    scanf("%s", ch + 1);
    int len = strlen(ch + 1);
    For(i, 1, len) {
        if(i != 1) cout << " ";
        cout << ch[i];
    }
    return 0;
}