//gfg topological sort

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//-------------------------------------------------------------------------

//topological sort using dfs

  map<int,int>mp;
  list<int>l;

  void dfs(int n,vector<int> adj[])
  {
    mp[n]=1;

    for(auto i: adj[n])
      if(mp[i]==0)
        dfs2(i,adj);

      l.push_front(n); //pushing the element to front to the list 
   }

    vector<int> topological_dfs(int V, vector<int> adj[]) 
    {
      vector<int> v;
      for(int i=0;i<V;i++)
        mp[i]=0;
      for(int i=0;i<V;i++)
        if(mp[i]==0)
          dfs2(i,adj);
        for(auto i:l)
          v.push_back(i);
        return v;

     }

//---------------------------------------------------------------------------    

//topological sort using bfs

      vector<int> topological_bfs(int n, vector<int> va[])
      {
        vector<int>  ans;

        int ind[n]={0};

        for(int i=0;i<n;i++) //calculating indegree of all node 
          for(auto ele:va[i])
            ind[ele]++;
        

        queue<int> q;

        for(int i=0;i<n;i++) //pushing the element with indegree zero in queue 
          if(ind[i]==0)        
            q.push(i);
  

          while(!q.empty())
          {
            int element =q.front();

            for(auto i:va[element])
            {

              ind[i]--;
              if(ind[i]==0) //when indegree will become zero , just push into queue
                q.push(i); //and explore that node 

            }
            ans.push_back(element);
            q.pop();

          }
          return ans;
        }

//---------------------------------------------------------------------------

      };

      int main(){

        vector<vector<int>> v={

          {1,2},
          {0,2},
          {0,5},
          {2,3},
          {3,4},

        };
        vector<int> va[6];

        for(int i=0;i<v.size();i++)
          va[v[i][0]].push_back(v[i][1]);


        Solution s;
        auto ans=s.topological_bfs(6,va);
        auto ans2=s.topological_dfs(6,va);


        cout<<"topological_bfs"<<"\n";
        for(auto i:ans)
          cout<<i<<" -> ";

        cout<<"\n";
        cout<<"topological_dfs"<<"\n";
        for(auto i:ans2)
          cout<<i<<" -> ";

      }
