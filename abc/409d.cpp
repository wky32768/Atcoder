#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
#define mp make_pair

using namespace std;

const int N = 4e5 + 5;

int t;
char ch[N];

using namespace std;
signed main() {
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ch[0] = '\0';
        scanf("%s", ch + 1);
        int ok = 0;
        For(i, 1, n - 1) if(ch[i] > ch[i + 1]) {
            int ed = i + 1;
            while(ed <= n && ch[ed] <= ch[i]) ed++;
            ed--;
            // cout << "debug " << i << " " << ed << endl;
            char temp = ch[i];
            For(j, i, ed - 1) ch[j] = ch[j + 1];
            ch[ed] = temp;
            cout << ch + 1 << endl;
            ok = 1;
            break;
        }
        if(!ok) cout << ch + 1 << endl;
    }

    return 0;
}
