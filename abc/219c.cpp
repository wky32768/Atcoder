#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
char ch[270];
int n,s[270];
struct node {
	char c[105];	
	friend bool operator < (node x,node y) {
		for(int i=0;i<min(strlen(x.c),strlen(y.c));i++)
			if(s[x.c[i]-'a'+30]!=s[y.c[i]-'a'+30]) return s[x.c[i]-'a'+30]<s[y.c[i]-'a'+30];
		return strlen(x.c)<strlen(y.c);	
	}
} a[50005];
signed main() {
	scanf("%s",ch+1);
	for(int i=1;i<=strlen(ch+1);i++) s[ch[i]-'a'+30]=i;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].c;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) cout<<a[i].c<<'\n';	
}
