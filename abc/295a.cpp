//You are given N strings W 1,W 2,…,W Nconsisting of lowercase English letters.If one or more of these strings equal and, not, that, the, or you, then print Yes; otherwise, print No.
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "not" || s == "and" || s == "the" || s == "you" || s == "that")
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
