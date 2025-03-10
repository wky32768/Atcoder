#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 3e5 + 10;
double r; 
int ans;
signed main() {
    cin >> r;
    int bian = 0, quater = 0;
    for(double i = 0.5; i <= r; i += 1) {
        if(abs(i - 0.5) <= 0.1) {
            double b = sqrt(r * r - i * i);
            int tmp = 0;
            if(b - (int)b >= 0.5) tmp = (int)b + 1;
            else tmp = (int)b;
            bian = tmp - 1;
        } else {
            double b = sqrt(r * r - i * i);
            int tmp = 0;
            if(b - (int)b >= 0.5) tmp = (int)b + 1;
            else tmp = (int)b;
            quater += (tmp - 1);
        }
    }
    // cout << "debug: " << quater << " " << bian << endl;
    cout << quater * 4 + bian * 4 + 1;
    return 0;
}