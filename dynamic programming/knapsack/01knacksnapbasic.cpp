#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(10000, vector<int>(10000, -1));

int knacksnap_recursive(vector<int> &weight, vector<int> &value, int w, int n)
{
    if (w == 0 || n == 0) //base condition
        return 0;
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    if (weight[n - 1] <= w)
        return max(
            value[n - 1] + knacksnap_recursive(weight, value, w - weight[n - 1], n - 1),
            knacksnap_recursive(weight, value, w, n - 1));
    else
        // If weight of the nth item is more
        // than Knapsack capacity W, then
        // this item cannot be included
        // in the optimal solution
        return knacksnap_recursive(weight, value, w, n - 1);
}
int knacksnap_recursive_memorization(vector<int> &weight, vector<int> &value, int w, int n)
{
    if (w == 0 || n == 0) //base condition
        return 0;
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    if (dp[n][w] != -1)
        return dp[n][w];
    else
    {
        if (weight[n - 1] <= w)
            return dp[n][w] = max(
                       value[n - 1] + knacksnap_recursive_memorization(weight, value, w - weight[n - 1], n - 1),
                       knacksnap_recursive_memorization(weight, value, w, n - 1));
        else
            // If weight of the nth item is more
            // than Knapsack capacity W, then
            // this item cannot be included
            // in the optimal solution
            return dp[n][w] = knacksnap_recursive_memorization(weight, value, w, n - 1);
    }
}
int knacksnap_topdown(vector<int> &weight, vector<int> &value, int w, int n)
{
    //here w==j and n==i;
    vector<vector<int>> dp2(weight.size() + 1, vector<int>(w + 1));
    //form base case w||j==0 then fill all places where j==0, same goes for n||i
    for (int i = 0; i < w + 1; i++)
        dp2[0][i] = 0;
    for (int i = 0; i < weight.size() + 1; i++)
        dp2[i][0] = 0;

    for (int i = 1; i < weight.size() + 1; i++)
    {

        for (int j = 1; j < w + 1; j++)
        {

            if (weight[i - 1] <= j)
                dp2[i][j] = max(value[i - 1] + dp2[i - 1][j - weight[i - 1]], dp2[i - 1][j]);
            else
                dp2[i][j] = dp2[i - 1][j];
        }
    }

    return dp2[weight.size()][w];
}
int main()
{

    vector<int> value = {1, 4, 5, 7};
    vector<int> weight = {1, 3, 4, 5};
    int w = 7;

    cout << knacksnap_recursive(weight, value, w, weight.size()) << endl;
    cout << knacksnap_recursive_memorization(weight, value, w, weight.size()) << endl;
    cout << knacksnap_topdown(weight, value, w, weight.size()) << endl;

    return 0;
}
