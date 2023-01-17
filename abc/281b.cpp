#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 105;
int n;
char ch[N];

void fail() {puts("No"); exit(0);}

signed main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    if(n != 8) fail();
    if(ch[1] < 'A' || ch[1] > 'Z') fail();
    if(ch[8] < 'A' || ch[8] > 'Z') fail();
    if(ch[2] == '0') fail();
    For(i, 2, 7) if(ch[i] < '0' || ch[i] > '9') fail();
    puts("Yes");
    return 0;
}