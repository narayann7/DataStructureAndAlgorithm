//leetcode
//219. Contains Duplicate II

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if(nums.size()<=1)return false;
    
        unordered_map<int,vector<int>>map;
        
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }
        
        for(auto i :map){
            if(i.second.size()>=2){
         return true;

            }
        }
        return false;
        
    }
};