//leetcode 128 number.
//its only the logic part 
#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
  if(nums.size()==0)
    return 0;
  
    set<int> s;
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }

    for (int x : s)
    {
        v.push_back(x);
    }
    int maxx = 0, c = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] + 1 == v[i + 1])
            c++;
        else
            c = 0;

        if (c >= maxx)
            maxx = c;
    }
    return maxx + 1;
}
//code contributed by: narayan
//git: narayann7
