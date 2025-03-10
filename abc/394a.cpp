#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 2005;
int n, ans;
char ch[N];

signed main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    For(i, 1, n) {
        if(ch[i] == '2') cout << ch[i];
    }
    return 0;
}