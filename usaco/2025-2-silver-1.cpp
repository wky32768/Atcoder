#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long
using namespace std;

const int N = 200005;

int t, n;

//如果最大的数在后面, 一定移到第一个
//否则, 先输出第一个, 再找最大的数

struct node {
    int num, at;
    friend bool operator < (node a, node b) {
        if(a.num != b.num) return a.num > b.num;
        else return a.at < b.at;
    }
} a[N];

bool ok(int x) {
    while(a[x + 1].num == a[x].num && a[x + 1].at == a[x].at + 1) x++;
    if(a[x + 1].num == a[x].num) return 0;
    return 1;
}

signed main() {
    cin >> t;
    while(t--) {
        cin >> n;
        For(i, 1, n) {
            cin >> a[i].num;
            a[i].at = i;
        }
        sort(a + 1, a + n + 1);
        int cnt = 1, last = 0;
        bool first = 0;
        while(a[cnt].at == last + 1 && ok(cnt)) {
            if(!first) {
                cout << a[cnt].num;
                first = 1;
            } else {
                cout << " " << a[cnt].num;
            }
            last = a[cnt].at;
            // cout <<" last" << last << " ";
            cnt++;
        }
        if(cnt > n) {
            puts("");
            continue;
        }
        // cout << " cut ";
        if(!first) {
            cout << a[cnt].num;
            first = 1;
        } else {
            cout << " " << a[cnt].num;
        }
        int temp = cnt;
        while(a[temp].num == a[temp + 1].num) temp ++;
        a[temp].at = -1;
        if(temp == cnt) cnt++;
        For(i, cnt, n) if(a[i].at > last) {
           if(!first) {
                cout << a[i].num;
                first = 1;
            } else {
                cout << " " << a[i].num;
            }
            last = a[i].at;
        }
        puts("");
    }



    return 0;
}