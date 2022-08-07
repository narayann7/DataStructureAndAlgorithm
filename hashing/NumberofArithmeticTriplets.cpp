2367. Number of Arithmetic Triplets

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        map<int,int> mp;
        
        for(auto i : nums){
            mp[i]++;
        }
        
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]+diff]!=0 && mp[nums[i]+diff+diff]!=0)
                count++;
        }
        
        return count;
        
    }
};