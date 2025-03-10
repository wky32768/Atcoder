#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;

const int N = 2e5 + 5;

int n;
char ch[16];

signed main() {
    scanf("%s", ch + 1);
    if(ch[4] == '3' && ch[5] == '1' && ch[6] == '6') {
        puts("No");
    } else {
        int num = (ch[4] - '0') * 100 + (ch[5] - '0') * 10 + (ch[6] - '0');
        if(num <= 349 && num != 0) puts("Yes");
        else puts("No");
    }




    return 0;
}