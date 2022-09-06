
//451. Sort Characters By Frequency :leetcode
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> mp;
        
        for(auto i : s){
            mp[i]++;
        }
        
        priority_queue<pair<int,char>> max_heap;
        
        for(auto i : mp ){
            pair<int,char> p;
            p.first=i.second;
            p.second=i.first;
            max_heap.push(p);
        }
        
        s="";
        
        while(!max_heap.empty()){

            auto i = max_heap.top();
            
            while(i.first--){
                s+=i.second;
            }
            
            max_heap.pop();
        }
        
        return s;        
    }
};