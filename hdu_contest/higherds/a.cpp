#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
struct book {
    int sm, ss, sday, tm, ts;
    bool bo;
} a[1005];
int lastm, lasts, nowm, nows;
int num, times, tottime;
char opt, ch[8];
signed main() {
    int days, nowday = 1;
    cin >> days;
    while(nowday <= days) {
        cin >> num >> opt;
        scanf("%s", ch + 1);
        nowm = (ch[1] - '0') * 10 + ch[2] - '0';
        nows = (ch[4] - '0') * 10 + ch[5] - '0';
        // cout << "day = " << nowday << '\n';
        if(num == 0) {
            double ans = (times == 0 ? 0 : tottime * 1.0 / times);
            // let 5.5 -> 6
            if(ans - (int)ans >= 0.5) ans = (int)ans + 1;
            else ans = (int)ans;
            cout << times << " " << (int)ans << '\n';
            times = 0;
            tottime = 0;
            // memset(a, 0, sizeof(a));
            nowday++;
        } else {
            if(opt == 'S') {
                a[num].sm = nowm;
                a[num].ss = nows;
                a[num].sday = nowday;
                a[num].bo = 1;
            } else if(opt == 'E') {
                if(a[num].bo == 1) {
                    times ++;
                    tottime += (nowday - a[num].sday) * 24 * 60 + (nowm - a[num].sm) * 60 + (nows - a[num].ss);
                    a[num].bo = 0;
                }
            }
            // lastm = nowm;
            // lasts = nows;
        }
    }
    return 0;
}