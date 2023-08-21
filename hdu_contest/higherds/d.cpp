#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
int n;
struct node {
    char name[10];
    int n, a[1005], sum, avg;
    friend bool operator < (node a, node b) {
        if(a.sum != b.sum) return a.sum > b.sum;
        else {
            return a.n < b.n;
        }
    }
} p[1005];
signed main() {
    cin >> n;
    For(i, 1, n) {
        scanf("%s", p[i].name + 1);
        cin >> p[i].n;
        For(j, 1, p[i].n) cin >> p[i].a[j];
        sort(p[i].a + 1, p[i].a + p[i].n + 1);
        int sum = 0;
        For(j, 1, p[i].n)
            if(p[i].a[j] != p[i].a[j - 1]) sum++;
        p[i].sum = sum;
    }
    sort(p + 1, p + n + 1);
    // cout << p[1].sum << " " <<p[2].sum << " " << p[3].sum << 
    '\n';
    For(i, 1, 3) {
        if(i <= n) cout << p[i].name + 1;
        else cout << "-";
        if(i != 3) cout << " ";
    }
    return 0;
}