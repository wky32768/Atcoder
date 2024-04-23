#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; ++i)
#define int long long

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int n;
char ch[105],ans[105];


signed main() {
    scanf("%s", ch + 1);
    int len = strlen(ch + 1), at = 0;
    For(i, 1, len) {
        if(ch[i] == '0') {
            ans[++at] = '0';
        } else if(ch[i] == '1') {
            ans[++at] = '1';
        } else if(ch[i] == 'B') {
            if(at > 0) {
                --at;
            }
        }
    }
    For(i, 1, at) {
        printf("%c", ans[i]);
    }


    return 0;
}