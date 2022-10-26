#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#define For(i, a, b) for(int i = a; i <= b; i ++)
#define int long long
const int N=520005;
using namespace std;
int n, x, cnt, tail;
int a[N], fa[N];
string str;
map <int, int > save;
signed main() {
    cin >> n;
    while(n--) {
        cin >> str;
        if(str == "ADD") {
            cin >> x;
            a[++cnt] = x;
            fa[cnt] = tail;
            tail = cnt;
        } else if(str == "DELETE") {
            tail=fa[tail];
        } else if(str == "SAVE") {
            cin >> x;
            save[x] = tail;
        } else if(str == "LOAD") {
            cin >> x;
            tail = save[x];
        }
        if(tail) cout << a[tail] << " ";
        else cout << "-1 ";
    }
    return 0;
}