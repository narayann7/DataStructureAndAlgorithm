////////Leetcode - 18
////// 4 SUM
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<vector<int>> st;
    vector<vector<int>> ans;
    long sum = 0;
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int s = j + 1;
            int e = n - 1;
            while (s < e)
            {
                sum = (long)nums[i] + nums[j] + nums[s] + nums[e];
                if (sum == target)
                {
                    st.insert({nums[i], nums[j], nums[s], nums[e]});
                    s++;
                    e--;
                }
                else if (sum < target)
                    s++;
                else
                    e--;
            }
        }
    }
    for (auto ch : st)
    {
        ans.push_back(ch);
    }
    return ans;
}
int main()
{
    vector<int> nums;
    nums={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> ans;
    ans=fourSum(nums,target);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
