//leetcode
//338. Counting Bits

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> arr;

    for(int i=0;i<=n;i++){


      int count=0;
      
      int num=i;

      while(num!=0){
        int x=num&1;
        if(x==1)
          count+=1;

        num>>=1;


      }
      arr.push_back(count);
      

    }return  arr;
  }
};