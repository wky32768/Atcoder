#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 3e5 + 5;

char ch[N];
int n;

signed main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    For(i, 1, n) ch[i] = 'A' + (ch[i] - 'a');
    printf("%s\n", ch + 1);
    return 0;
} 