#include <bits/stdc++.h>
#include <cstdio>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
const int N = 200005;
int n, m; // 0 ~ n - 1 !
int p[1005][1005];
map <int, double> mp;
bool cmp(int a, int b) {
    return abs(a) < abs(b);
}
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
    if(f == -1) return x * f - 1;
    else return x * f + 1;
}
void make(int x) {
    if(x == -1) cout <<"-0";
    else if(x == 1) cout << "0";
    else if(x < 0) cout << x + 1;
    else if(x > 0) cout << x - 1;
}
signed main() {
    cin >> n >> m;
    For(i, 1, m) {
        cin >> p[i][0];
        For(j, 1, p[i][0]) {
            p[i][j] = read();
            // cin >> p[j];
            // if(p[j] < 0) p[j] --;
            // else p[j] ++;
        }

    }
    int a, b;
    a = read(), b = read();
    int aa = a, bb = b;
    if(a > b) swap(a, b);

    For(i, 1, m) {
        int k = p[i][0];
        int havea = 0, haveb = 0;
        For(j, 1, k) if(p[i][j] == a) havea = j;
        For(j, 1, k) if(p[i][j] == b) haveb = j;
        if(havea) {
            For(l, 1, k) {
                int tempx = p[i][havea], tempy = p[i][l];
                if(tempx * tempy > 0) continue;
                if(l == havea) continue;
                if(tempx > tempy) swap(tempx, tempy);
                mp[tempx * 2000 + tempy] += 1.0 / k;
                // cout << "debug " << tempx << " " << tempy << " " << mp[tempx * 2000 + tempy] << '\n';
            }
        }
        if(haveb) {
            For(l, 1, k) {
                int tempx = p[i][haveb], tempy = p[i][l];
                if(tempx * tempy > 0) continue;
                if(l == haveb) continue;
                if(tempx > tempy) swap(tempx, tempy);
                mp[tempx * 2000 + tempy] += 1.0 / k;
                // cout << "debug " << tempx << " " << tempy << " " << mp[tempx * 2000 + tempy] << '\n';
            }
        }
        if(havea && haveb) {

            int tempx = a, tempy = b;
            if(tempx > tempy) swap(tempx, tempy);
            mp[tempx * 2000 + tempy] -= 1.0 / k;
        }
    }



    double besta = 0, bestb = 0;
    vector <int> whoa, whob;
    whoa.clear(); whob.clear();
    For(i, -n, n) {
        int tempx = a, tempy = i;
        if(tempx > tempy) swap(tempx, tempy);
        if(tempx * tempy > 0) continue;
        // cout <<"debug txty " << tempx << " " << tempy << " " << mp[tempx * 2000 + tempy] << '\n';
        if(mp[tempx * 2000 + tempy] > besta) {
            besta = mp[tempx * 2000 + tempy];
            whoa.clear();
            whoa.push_back(i);
        } else if(mp[tempx * 2000 + tempy] == besta) {
            whoa.push_back(i);
        }
    }
    For(i, -n, n) {
        int tempx = b, tempy = i;
        if(tempx > tempy) swap(tempx, tempy);
        if(tempx * tempy > 0) continue;
        // cout <<"debug txty " << tempx << " " << tempy << " " << mp[tempx * 2000 + tempy] << '\n';
        if(mp[tempx * 2000 + tempy] > bestb) {
            bestb = mp[tempx * 2000 + tempy];
            whob.clear();
            whob.push_back(i);
            // cout << "debug " << i <<" inserted\n";
        } else if(mp[tempx * 2000 + tempy] == bestb) {
            whob.push_back(i);
        }
    }
    
    // puts("debug");
    // For(i, 0, whoa.size() - 1) cout << whoa[i] << " ";
    // puts("");
    // For(i, 0, whob.size() - 1) cout << whob[i] << " ";
    // puts("");

    // puts("debug ends here");

    
    sort(whoa.begin(), whoa.end(), cmp);
    sort(whob.begin(), whob.end(), cmp);

    if(find(whoa.begin(), whoa.end(), b) != whoa.end() && find(whob.begin(), whob.end(), a) != whob.end()) {
        if(a == aa) {make(a); putchar(' '); make(b);}
        else {make(b); putchar(' '); make(a);}
    } else {
        if(a == aa) {
            For(i, 0, whoa.size() - 1) {
                make(a);  cout << " "; make(whoa[i]); cout << '\n';
            }
            For(i, 0, whob.size() - 1) {
                make(b); cout << " "; make(whob[i]);cout << '\n';
            }
        } else {
            For(i, 0, whob.size() - 1) {
                make(b); cout << " "; make(whob[i]); cout << '\n';
            }
            For(i, 0, whoa.size() - 1) {
                make(a); cout << " "; make(whoa[i]); cout << '\n';
            }
        }
    }
    return 0;
}