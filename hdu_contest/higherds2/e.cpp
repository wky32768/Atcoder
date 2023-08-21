#include <bits/stdc++.h>
#include <cstdio>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
const int N = 200005;
int n, g, k;
struct node {
    string name;
    int fs;
    friend bool operator < (node a, node b) {
        if(a.fs != b.fs) return a.fs > b.fs;
        else return a.name < b.name;
    }
} a[N];
signed main() {
    cin >> n >> g >> k;
    For(i, 1, n) {
        cin >> a[i].name >> a[i].fs;
    }
    sort(a + 1, a + n + 1);
    int tot = 0;
    For(i, 1, n) {
        if(a[i].fs >= g) tot += 50;
        else if(a[i].fs >= 60) tot += 20;
    }
    cout << tot << '\n';
    int num = 0;
    For(i, 1, n) {
        if(a[i].fs != a[i - 1].fs) {
            num = i;
        }
        if(num > k) break;
        cout << num << " " << a[i].name << " " << a[i].fs << '\n';
    }


    return 0;
}