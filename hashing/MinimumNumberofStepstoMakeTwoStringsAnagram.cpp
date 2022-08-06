1347. Minimum Number of Steps to Make Two Strings Anagram : leetcode
class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp;
        
        for(auto i:s){
            mp[i]++;
        }
        for(auto i:t){
            mp[i]--;
        }
        int count=0;
        for(auto i:mp){
            if(i.second<=-1)
                count+=abs(i.second );
        }
        
        return count;
        
        
        
    }
};