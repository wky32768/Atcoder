#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1000005;
int t, x, y, fib[N];
signed main() {
    cin>>t;
    fib[1]=fib[2]=1;
    For(i,3,1000003) fib[i]=fib[i-1]+fib[i-2];
    while(t--) {
        cin>>x>>y;
        int at=0;
        For(i,1,1000002) if(fib[i]==x && fib[i+1]==y) {
            at=i; break;
        }
        if(at<=y) {
            cout<<"sc";
            for(int i=1;i<=at-1;i++) cout<<"tc";
            puts("");
        } else puts("Noooooooo!");
    }
    return 0;

}