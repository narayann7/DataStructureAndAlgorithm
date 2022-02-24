//leetcode
//1013. Partition Array Into Three Parts With Equal Sum

class Solution {
public:
   bool canThreePartsEqualSum(vector<int>& arr) {
       int total = accumulate(arr.begin() , arr.end() , 0);
        if(total %3 != 0 ) return false;
        int required = total/3;
        int sum = 0 , count = 0;
        for(int i=0 ; i<arr.size() ; i++)
        {
            sum += arr[i];
            if(sum == required)
            {
                count++;
                sum=0;
            }
        }
        return count>=3;
    }
};