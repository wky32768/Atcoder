#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
char ch[5];
signed main() {
    scanf("%s",ch+1);
    if(ch[1]!=ch[2] && ch[1]!=ch[3] && ch[2]!=ch[3]) puts("6");
    else if(ch[1]==ch[2] && ch[1]==ch[3] && ch[2]==ch[3]) puts("1");
    else puts("3");
    return 0;
}