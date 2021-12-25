#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long 
using namespace std;
int a,b;
signed main() {
    cin>>a>>b;
    int ans=1;
    for(int i=1;i<=a-b;i++) {
    	ans=ans*32;	
    }
    cout<<ans;
    return 0;
}
