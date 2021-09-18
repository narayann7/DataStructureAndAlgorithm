

#include<bits/stdc++.h>
using namespace std;

class cycleCheckDirectedGraph{
public:

  bool dfs(int n, vector<int> v[],vector<int> &hash)
  {

    hash[n]++;


    for(auto i : v[n])
    {

      if(hash[i]==0)
      {
        hash[i]++;
        bool ans = dfs(i,v,hash);
        hash[i]--;

        if(ans==true)
          return true;

      }
      else if(hash[i]==2)
        return true;

    }
    return false;
  }

  bool isCyclic_dfs(int n, vector<int> v[]) {

    vector<int> hash(n,0);
    bool ans=false;

    for(int i=0;i<n;i++)
    {
      if(hash[i]==0)
      {
        hash[i]++;
        ans=dfs(i,v,hash);
        hash[i]--;
        if(ans==true)
          return true;

      }
    }
    return false;

  }

  bool isCyclic_bfs(int n, vector<int> v[]) {

    vector<int> indegre (n,0);


    for(int i=0;i<n;i++)
      for(auto j : v[i])
        indegre[j]++;

      queue<int> q;

      for(int i=0;i<n;i++)
        if(indegre[i]==0)
          q.push(i);

        int count =0;


        while(!q.empty())
        {

          int element = q.front();
          q.pop();
          count++;
          for(auto i:v[element])
          {
            indegre[i]--;
            if(indegre[i]==0)
              q.push(i);
          }

        }

        if(count==n)
          return false;
        else
          return true;

      }

    };

    int main(){

      vector<vector<int>> v={
       {6,5},
       {5 ,3},
       {3 ,1},
       {1 ,2},
       {2 ,4},
       {4, 0}
     };

     Solution s;
     int n=7;
     vector<int> va[n];

     for(int i=0;i<v.size();i++)
      va[v[i][0]].push_back(v[i][1]);


    cout<<s.isCyclic_bfs(n,va);
    cout<<s.isCyclic_dfs(n,va);

  }
