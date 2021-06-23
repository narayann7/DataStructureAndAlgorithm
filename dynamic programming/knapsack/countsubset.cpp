#include <bits/stdc++.h>
using namespace std;

int knacksnap_topdown_countsubset(vector<int> &arr, int key, int n)
{
    //here w==j and n==i;
    vector<vector<int>> dp(arr.size() + 1, vector<int>(key + 1));
    //form base case w||j==0 then fill all places where j==0, same goes for n||i
    for (int i = 0; i < key + 1; i++)
        dp[0][i] = 0;
    for (int i = 0; i < arr.size() + 1; i++)
        dp[i][0] = 1;

    for (int i = 1; i < arr.size() + 1; i++)
    {

        for (int j = 1; j < key + 1; j++)
        {

            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[arr.size()][key];
}
int main()
{

    vector<int> arr = {1, 4, 5, 7, 8, 6, 3, 9};
    int key = 3;
    cout<<knacksnap_topdown_countsubset(arr, key, arr.size())<<endl;

    return 0;
}
