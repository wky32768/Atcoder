#include <bits/stdc++.h>
#include <cstdio>
#define For(i, a, b) for(int i = a;i <= b; i++)
using namespace std;
int pa, pb, a, b, c;
signed main() {
    cin >> pa >> pb >> a >> b >> c;
    if(pa > pb && 3 - (a + b + c) >= 1) {
        cout << "The winner is " << "a: " << pa << " + " << 3 -(a + b + c) << '\n';
    } else if(pa > pb) {
        cout << "The winner is " << "b: " << pb << " + " << a + b + c << '\n';
    } else if(pa < pb && a + b + c >= 1) {
        cout << "The winner is " << "b: " << pb << " + " << a + b + c << '\n';
    } else {
        cout << "The winner is " << "a: " << pa << " + " << 3 -(a + b + c) << '\n';
    }
    
    return 0;
}