//We have a board with R rows running horizontally and C columns running vertically. Let (i,j) denote the square at the i-th row from the top and j-th column from the left.You are given characters B i,jrepresenting the current states of (i,j). . represents an empty square; # represents a square with a wall; 1, 2,…, 9 represent a square with a bomb of power 1,2,…,9, respectively.At the next moment, all bombs will explode simultaneously. When a bomb explodes, every square whose Manhattan distance from the square with the bomb is not greater than the power of the bomb will turn into an empty square. Here, the Manhattan distance from (r 1​,c 1) to (r 2 ,c 2) is ∣r1−r 2∣+∣c 1−c 2∣.Print the board after the explosions.
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
int main()
{
    int r, c;
    cin >> r >> c;
    char a[r][c];
    for (int i = 0; i < r; i++)
    {
        cin >> a[i];
    }
    int b[r][c];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c;j++)
        {
            if(a[i][j]!='#')
            {
                if(a[i][j]=='.')
                {
                    b[i][j] = 0;
                }
                else
                {
                    b[i][j] = a[i][j] - '0';
                }
            }
        }
    }
    For(i, 0, r - 1) For(j, 0, c - 1) if(b[i][j]) {
        int temp = b[i][j];
        For(x, max(0, i - temp), min(r - 1, i + temp)) 
            For(y, max(0, j - temp), min(c - 1, j + temp)) 
                if(abs(x - i) + abs(y - j) <= temp) {a[x][y] = '.';}
    }
    For(i, 0, r - 1) {
        For(j, 0, c - 1) {
            if(a[i][j] == '#') cout << '#';
            else if(a[i][j] == '.') cout << '.';
        }
        cout << endl;
    }
}