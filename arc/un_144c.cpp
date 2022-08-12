#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n, k;
int ans[300005];
signed main() {
    cin>>n>>k;
    if(k>n/2) {
        cout<<-1<<endl;
        return 0;
    }
    int kk=k*2, cnt=0;
    int temp=(n%kk==0?(n/kk):(n/kk-1));
    For(i,1,temp) {
        int start=(i-1)*kk+1;
        int end=i*kk;
        // cout<<"start="<<start<<'\n';
        // cout<<"end="<<end<<'\n';
        For(j,start+k,end) ans[++cnt]=j;
        For(j,start,start+k-1) ans[++cnt]=j; 
    }
    if(n%kk) {
        int start=n-n%kk-kk+1, end=n;
        For(j,start+k,end) ans[++cnt]=j;
        For(j,start,start+k-1) ans[++cnt]=j;
    }

    return 0;
}