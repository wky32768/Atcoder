#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100005;
char ch1[4], ch2[4];
int a1[4], a2[4];
signed main() {
    For(i,1,3) {
        cin>>ch1[i]; 
        if(ch1[i]=='R') a1[i]=1;
        else if(ch1[i]=='G') a1[i]=2;
        else if(ch1[i]=='B') a1[i]=3;
    }
    For(i,1,3) {
        cin>>ch2[i];
        if(ch2[i]=='R') a2[i]=1;
        else if(ch2[i]=='G') a2[i]=2;
        else if(ch2[i]=='B') a2[i]=3;
    }
    int n1=0, n2=0;
    For(i,1,3) For(j,i+1,3) if(a1[i]>a1[j]) n1++;
    For(i,1,3) For(j,i+1,3) if(a2[i]>a2[j]) n2++;
    if(n1%2==n2%2) puts("Yes"); else puts("No");
}