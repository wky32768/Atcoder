#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200005;
char ch[N];
int n, a[N];
signed main() {
	scanf("%s", ch+1);
	n=strlen(ch+1);
	For(i,1,n) a[i]=(int)ch[i];
	sort(a+1, a+n+1);
	For(i,1,n) cout<<(char)a[i];
	return 0;
}

