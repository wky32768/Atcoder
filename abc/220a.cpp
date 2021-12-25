#include <iostream>
#include <cstdio>
using namespace std;
int a,b,c; 
signed main() {
    cin>>a>>b>>c;
    for(int i=a;i<=b;i++) {
        if(i%c==0) {
            cout<<i;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}
