#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int l,r;
char ch[100005];
signed main() {
	cin>>l>>r;
	scanf("%s",ch+1);
	for(int i=1;i<=l-1;i++) cout<<ch[i];
	for(int i=r;i>=l;i--) cout<<ch[i];
	for(int i=r+1;i<=strlen(ch+1);i++) cout<<ch[i];
	return 0;
}
