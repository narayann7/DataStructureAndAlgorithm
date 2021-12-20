#include <bits/stdc++.h>
using namespace std;

int minswap(vector<int> &x)
{
    map<int, int> mp;
    for (int i = 0; i < x.size(); i++)
    {
        mp[x[i]] = i;
    }
    int i = 0, c = 0;
    for (auto s : mp)
    {
        if (s.first != x[i])
        {
            int k = s.second, k1;
            k1 = mp[x[i]];
            mp[x[i]] = mp[x[k]];
            mp[x[k]] = k1;
            swap(x[i], x[k]);
            c++;
        }
        i++;
    }
    return c;
}
int solve(vector<int> &x)
{
    vector<int> x1 = x;
    reverse(x1.begin(), x1.end());
    return min(minswap(x), minswap(x1));
}
//git-narayann7
int main()
{
    vector<int> arr = {2,4,1,3,5};
    cout << solve(arr) << endl;
    return 0;
}
