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

const int N = 10005;
int t;
int tota, totb, totc;
struct node {
    int t, id, x, y, z;
} a[N];
queue <node> qq;
bool yyes[N];

signed main() {
    cin >> t;
    while(t--) {
        int q;
        cin >> q;
        while(!qq.empty()) qq.pop();
        memset(yyes, 0, sizeof yyes);
        int ta = 0, tb = 0, tc = 0;
        For(i, 1, q) {
            a[i].t = read(), a[i].id = read(), a[i].x = read(), a[i].y = read(), a[i].z = read();
            if(a[i].id == 1) {ta += a[i].x; tb += a[i].y; tc +=a[i].z;}
        }
        For(i, 1 ,q) if(a[i].id == 2){
            if(ta + tc >= a[i].y && tb + tc >= a[i].z && a[i].y - min(tc, min(a[i].y, a[i].z)) <= ta && a[i].z - min(tc, min(a[i].y, a[i].z)) <= tb) {
                    //ok
                        int consume_c = min(tc, min(a[i].y, a[i].z));
                        int consume_a = a[i].y - consume_c;
                        int consume_b = a[i].z - consume_c;

                        ta -= consume_a;
                        tb -= consume_b;
                        tc -= consume_c;
                        yyes[a[i].x] = 1;
                    } 
        }
        For(i, 1, q) {
            int t = a[i].t, opt = a[i].id, x = a[i].x, y = a[i].y, z = a[i].z;
            if(opt == 1) {
                tota += x;
                totb += y;
                totc += z;
                while(!qq.empty()) {
                    node now = qq.front();
                    if(tota + totc >= now.y && totb + totc >= now.z && now.y - min(totc, min(now.y, now.z)) <= tota && now.z - min(totc, min(now.y, now.z)) <= totb) {
                    //ok
                        int consume_c = min(totc, min(now.y, now.z));
                        int consume_a = now.y - consume_c;
                        int consume_b = now.z - consume_c;

                        tota -= consume_a;
                        totb -= consume_b;
                        totc -= consume_c;
                        cout << t << " " << now.x << '\n';
                        qq.pop();
                    } else break;
                }
            } else {
                if(tota + totc >= y && totb + totc >= z && y - min(totc, min(y, z)) <= tota && z - min(totc, min(y, z)) <= totb && yyes[x]) {
                    //ok
                    int consume_c = min(totc, min(y, z));
                    int consume_a = y - consume_c;
                    int consume_b = z - consume_c;
                    tota -= consume_a;
                    totb -= consume_b;
                    totc -= consume_c;
                    cout << t << " " << x << '\n';
                } else {
                    qq.push((node) {t, opt, x, y, z});
                }
            }
            // cout << "debug " << tota << " " << totb << " " << totc << '\n';
        }
        puts("FINISH");
        while(!qq.empty()) {
            node now = qq.front();
            cout << now.x << '\n';
            qq.pop();
        }
    }
    return 0;
}