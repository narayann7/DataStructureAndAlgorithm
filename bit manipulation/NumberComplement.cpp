476. Number Complement : leetcode

class Solution {
public:
    string  decToBinary(int n)
{ 
    string ans=""; 
   
    while (n > 0) {
 
       ans= to_string(n % 2)+ans;
        n=n / 2;

    }
    return ans;
    }

    int findComplement(int num) {
        
        string number=decToBinary(num);
        string fliped_number="";
        for(auto i : number){
            if(i=='0')
                fliped_number+="1";
            else
                fliped_number+="0";
        }
        num = stoi(fliped_number, 0, 2);
        return num;
        
    }
};