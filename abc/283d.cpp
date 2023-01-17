#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 300005;
char ch[N];
int tot_sum[N][30], lastat[N], n, tot, let_now[30];

signed main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    For(i, 1, n) {
        For(j, 0, 25) tot_sum[i][j] = tot_sum[i - 1][j];
        if(ch[i] == '(') {
            tot ++;
            lastat[tot] = i;
        } else if(ch[i] == ')') {
            For(j, 0, 25) let_now[j] = max(0ll,  let_now[j] - (tot_sum[i][j] - tot_sum[lastat[tot]][j]));
            // cout << "debug " << i << " " << lastat[tot] << '\n';
            tot --;
        } else {
            tot_sum[i][ch[i] - 'a'] ++;
            let_now[ch[i] - 'a'] ++;
            if(let_now[ch[i] - 'a'] > 1) {puts("No"); return 0;}
        }
    }
    puts("Yes");
    return 0;
}