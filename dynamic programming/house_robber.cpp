//198. House Robber
//leetcode

class Solution {
public:
   int rob(vector<int> &v)
{
       if(v.size()==0)
           return 0;
        if(v.size()==1)
           return v[0];
           

   vector<int> vv(v.size());

    vv[0] = v[0];
    vv[1] = max(v[0], v[1]);

    for (int i = 2; i < v.size(); i++)
        vv[i] = max(vv[i - 1], (vv[i - 2] + v[i]));

    return vv[v.size()-1];
}
};