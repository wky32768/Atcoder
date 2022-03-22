#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, -1, 0, 1};
int n, dir, nowx, nowy;
char ch[N];
signed main() {
    cin>>n;
    scanf("%s", ch+1);
    For(i,1,n) {
        if(ch[i]=='S') nowx+=dx[dir], nowy+=dy[dir];
        else dir=(dir+1)%4;
    }
    cout<<nowx<<" "<<nowy<<'\n';
    return 0;
}