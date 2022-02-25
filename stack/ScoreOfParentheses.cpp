//leetcode
//856. Score of Parentheses

class Solution {
public:
int scoreOfParentheses(string s) {
  stack<int> stack;

  int ans=0;

  for(int i=0;i<s.length();i++){

    if(s[i]=='(')
    {
      stack.push(0);
    }
    else
    {
      if(stack.top()==0)
      {
        stack.pop();
        stack.push(1);
      }
      else
      {
        int temp_ans=0;
        while(stack.top()!=0&&!stack.empty()){
          temp_ans+=stack.top();
          stack.pop();
        }
          stack.pop();
        temp_ans*=2;
        stack.push(temp_ans);
      }


    }


  }


  while(!stack.empty()){
   ans+=stack.top();
   stack.pop();
 }
 return ans;

}


};