//leetcode no. :52 
//only the logic part

#include <bits/stdc++.h>
using namespace std;

bitset<100> dia, dia2, col;//bitset uses only constant as put acc. to question
/*this method use bits ,
insted of using linear search in the isSafe function 
bit set helps in checking the col and diagonal's in O(1),
in this question u should not break the recursion tree ,
insted of bit u can use hashing */

void solve(int r, int n, int &ans)
{
    if (r == n)
    {
        ans++;
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (col[c] == 0 && dia[r - c + n - 1] == 0 && dia2[c + r] == 0)
        {
            col[c] = dia[r - c + n - 1] = dia2[c + r] = 1;
            solve(r + 1, n, ans);
            col[c] = dia[r - c + n - 1] = dia2[c + r] = 0; //ones u get the ans return back and make bit as 0, for next aviable answer
        }
    }
}
int totalNQueens(int n)
{
    int ans = 0;
    solve(0, n, ans);
    return ans;
}

int main()
{
    int n;
    cout << "enter the  Number" << endl;
    cin >> n;
    cout << totalNQueens(n) << endl;
}
