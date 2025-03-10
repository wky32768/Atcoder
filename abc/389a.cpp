#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
char ch[5];
signed main() {
    scanf("%s", ch + 1);
    cout << ((ch[1] - '0') * (ch[3] - '0'));
    return 0;
}