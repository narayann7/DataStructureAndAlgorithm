//leetcode
//3. Longest Substring Without Repeating Characters

class Solution {

public:
  int lengthOfLongestSubstring(string s) {
    if(s.length()==0)
      return 0;
    if(s.length()==1)
     return 1;
   unordered_map<char,int>map;
   unordered_map<char,int>index;
   int max_length=-1;
   string temp="";


   for(int i=0;i<s.length();i++){
     int x=map[s[i]]++;
     index[s[i]]=index[s[i]]+i;


     if(x==0){
      temp+=s[i];

    }
    else{
      int temp_length=temp.length();
      max_length=max(max_length,temp_length);
      int temp_index=index[s[i]]-i;


      i=temp_index;

      temp="";

      map.clear();
      index.clear();


    }

  }
  int temp_length=temp.length();

  max_length=max(max_length,temp_length);


  return max_length;

}

};