791. Custom Sort String : leetcode

class Solution {
public:
  string customSortString(string order, string s) {

    map<char,int>mp;
    for(auto i:s){
      mp[i]++;
    }
    string ans="";

    for(auto i : order){

      if(mp[i]>0)
      {
        int n=mp[i];
        while(n--){
          ans+=i;
          mp[i]--;
        }
        

      }

    }
    for(auto i:mp){

      if(i.second!=0){

        int n=i.second;
        while(n--){
          ans+=i.first;
        }
      }

    }

    return ans;



  }
};