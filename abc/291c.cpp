#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>

#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long

const int N = 3e5 + 5;
using namespace std;

int n, a[N];
char ch[N];
map <int, bool> mp;

signed main() {
    cin >> n;
    scanf("%s", ch + 1);
    int posx = 0, posy = 0;
    mp[0] = 1;
    For(i, 1, n) {
        if(ch[i] == 'L') posx -= 1;
        if(ch[i] == 'R') posx += 1;
        if(ch[i] == 'D') posy -= 1;
        if(ch[i] == 'U') posy += 1;
        if(mp[posx * 200003 + posy] == 1) {
            puts("Yes"); return 0;
        }
        mp[posx * 200003 + posy] = 1;
    }
    puts("No");
    return 0;
}