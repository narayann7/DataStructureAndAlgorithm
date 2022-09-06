
//658. Find K Closest Elements :leetcode
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        priority_queue<pair<int,int>>max_heap;
        
        for(auto i : arr){
            max_heap.push(make_pair(abs(i-x),i));
            
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        
        while(k--){
            ans.push_back(max_heap.top().second );
            max_heap.pop();
            
        }

        sort(ans.begin(),ans.end());
        return ans;
        
    }
};