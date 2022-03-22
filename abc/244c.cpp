#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int n, rd, x;
bool used[N];
signed main() {
    cin>>n;
    cout.flush();
    cout<<"1\n";
    used[1]=1; cin>>rd;
    while(rd) {
        used[rd]=1;
        For(i,1,2*n+1) if(!used[i]) {cout<<i<<'\n'; used[i]=1;break;}
        cin>>rd;
    }
    return 0;
}