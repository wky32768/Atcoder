#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100005;
char a[N],b[N];
int ans[N],cnt;
signed main() {
    scanf("%s",a+1);
    scanf("%s",b+1);
    int n=strlen(a+1);
    for(int i=1;i<=n;i++) if(a[i]!=b[i]) ans[++cnt]=i;
    if(cnt>2 || cnt==1) {puts("No"); return 0;}
    if(cnt==0) {puts("Yes"); return 0;}
    if(abs(ans[1]-ans[2])==1 && a[ans[1]]==b[ans[2]] && a[ans[2]]==b[ans[1]]) {puts("Yes");return 0;}
    puts("No");
    return 0;
}
