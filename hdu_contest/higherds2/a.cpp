#include <bits/stdc++.h>
#include <cstdio>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
char ch;
int n;
const int N = 1005;
struct node {
    char c[N];
} a[N];
signed main() {
    cin >> ch >> n;
    getchar();
    For(i, 1, n) {
        // gets(a[i].c + 1);
        For(j, 1, n) a[i].c[j] = getchar();
        getchar();
    }
    bool duicheng = 1;
    For(i, 1, n)
        For(j, 1, n)
            if(a[i].c[j] != a[n + 1 - i].c[n + 1 - j]) 
                duicheng = 0;
    if(duicheng)
        puts("bu yong dao le");
    For(i, 1, n) {
        For(j, 1, n) {
            // cout << "debug " << n + 1 - i << " " << n + 1 - j << '\n';
            cout << (a[n + 1 - i].c[n + 1 - j] == '@' ? ch : ' ');
        }
        puts("");
    }
    return 0;

}