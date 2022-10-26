#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=105;
char ch[N];
int ok[N];
signed main() {
    scanf("%s", ch+1);
    if(ch[1]!='0') {puts("No"); return 0;}
    if(ch[7]=='1') ok[1]=1;
    if(ch[4]=='1') ok[2]=1;
    if(ch[2]=='1' || ch[8]=='1') ok[3]=1;
    if(ch[1]=='1' || ch[5]=='1') ok[4]=1;
    if(ch[3]=='1' || ch[9]=='1') ok[5]=1;
    if(ch[6]=='1') ok[6]=1;
    if(ch[10]=='1') ok[7]=1;
    For(i,1,7) For(j,i+2,7) if(ok[i]==1 && ok[j]==1) {
        bool okk=1;
        For(k,i+1,j-1) if(ok[k]==1) okk=0;
        if(okk==1) {puts("Yes"); return 0;}
    }
    puts("No");
    return 0;
}