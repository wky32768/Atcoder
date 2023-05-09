#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for(int i = a; i <= b;i ++)
using namespace std;
int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}

void write(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) write(x / 10);
    putchar('0' + x % 10);
    return;
}

const int N = 105;
int t, n;
char ch[N];
map <int, int> mp;
const int mod = 19260817;

signed main() {
    cin >> t;
    while(t --) {
        cin >> n;
        mp.clear();
        For(temp, 1, n) {
            scanf("%s", ch + 1);
            bool is_equal = 0;
            For(i, 1, strlen(ch + 1)) {
                if(ch[i] == '=') is_equal = 1;
            }
            if(is_equal) {
                int has = 1, e = 0;
                For(i, 1, strlen(ch + 1)) {
                    if(ch[i] == '=') {e = i; break;}
                    has = (has * 26 + ch[i] - 'a') % mod;
                }
                int bds = 0, fh = 0;
                For(i, 1, strlen(ch + 1)) 
                    if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*') {bds = 1; fh = i;}
                if(bds == 0) {
                    int isnum = 0, isbl = 0, num = 0, hass = 1;
                    For(i, e + 1, strlen(ch + 1)) {
                        if(ch[i] >= '0' && ch[i] <= '9') isnum = 1, num = num * 10 + ch[i] - '0';
                        else isbl = 1, hass = (hass * 26 + ch[i] - 'a') % mod;
                    }
                    if(isnum) mp[has] = num;
                    else mp[has] = mp[hass];
                } else {
                    int isnum = 0, isbl = 0, num = 0, hass = 1;
                    For(i, e + 1, fh - 1) {
                        if(ch[i] >= '0' && ch[i] <= '9') isnum = 1, num = num * 10 + ch[i] - '0';
                        else isbl = 1, hass = (hass * 26 + ch[i] - 'a') % mod;
                    }
                    int isnum2 = 0, isbl2 = 0, num2 = 0, hass2 = 1;
                    For(i, fh + 1, strlen(ch + 1)) {
                        if(ch[i] >= '0' && ch[i] <= '9') isnum2 = 1, num2 = num2 * 10 + ch[i] - '0';
                        else isbl2 = 1, hass2 = (hass2 * 26 + ch[i] - 'a') % mod;
                    }
                    int final1 = 0, final2 = 0;
                    if(isnum) final1 = num; else final1 = mp[hass];
                    if(isnum2) final2 = num2; else final2 = mp[hass2];
                    cout << "debug " << final1 << " " << final2 << '\n';
                    if(ch[fh] == '+') mp[has] = final1 + final2;
                    else if(ch[fh] == '-') mp[has] = final1 - final2;
                    else if(ch[fh] == '*') mp[has] = final1 * final2;
                }

            } else {
                int has = 1;
                int bds = 0, fh = 0;
                For(i, 1, strlen(ch + 1)) 
                    if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*') {bds = 1; fh = i;}
                if(bds == 0) {
                    For(i, 1, strlen(ch + 1)) 
                        has = (has * 26 + ch[i] - 'a') % mod;
                    cout << mp[has] << '\n';
                } else {
                    int isnum = 0, isbl = 0, num = 0, hass = 1;
                    For(i, 1, fh - 1) {
                        if(ch[i] >= '0' && ch[i] <= '9') isnum = 1, num = num * 10 + ch[i] - '0';
                        else isbl = 1, hass = (hass * 26 + ch[i] - 'a') % mod;
                    }
                    int isnum2 = 0, isbl2 = 0, num2 = 0, hass2 = 1;
                    For(i, fh + 1, strlen(ch + 1)) {
                        if(ch[i] >= '0' && ch[i] <= '9') isnum2 = 1, num2 = num2 * 10 + ch[i] - '0';
                        else isbl2 = 1, hass2 = (hass2 * 26 + ch[i] - 'a') % mod;
                    }
                    int final1 = 0, final2 = 0;
                    if(isnum) final1 = num; else final1 = mp[hass];
                    if(isnum2) final2 = num2; else final2 = mp[hass2];
                    if(ch[fh] == '+') cout << final1 + final2 << '\n';
                    else if(ch[fh] == '-') cout << final1 - final2 << '\n';
                    else if(ch[fh] == '*') cout << final1 * final2 << '\n';
                }
            }
        }
    }




    return 0;
}