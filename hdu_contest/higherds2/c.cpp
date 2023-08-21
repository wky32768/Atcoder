#include <bits/stdc++.h>
#include <cstdio>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
struct node {
    string name;
    int num;
} a[100005];
int n, tot;
double avg;
signed main() {
    cin >> n;
    For(i, 1, n) {
        cin >> a[i].name >> a[i].num;
        tot += a[i].num;
    }
    avg = tot / (2.0 * n);
    double closest = 10000000;
    int at = 0;
    For(i, 1, n) {
        if(fabs(a[i].num - avg) < closest) {
            closest = fabs(a[i].num - avg);
            at = i;
        }
    }
    cout << (int)avg << " " << a[at].name << '\n';
    return 0;
}