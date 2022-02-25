//leetcode
//187. Repeated DNA Sequences
class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string>ans;
    if(s.length()<=10){
      return ans;
    }

    
    unordered_map<string,int>map;
    for(int i=0;i<s.length()-9;i++ )
      map[s.substr(i,10)]++;


    for(auto i:map){
      if(i.second>=2)
        ans.push_back(i.first);

    }

    return ans;

  }
};