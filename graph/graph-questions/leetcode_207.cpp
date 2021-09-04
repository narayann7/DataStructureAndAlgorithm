//207. Course Schedule
//topological sort


class Solution {
public:
	map<int,int>mp;
	list<int>l;
	
	void dfs(int n,vector<int> adj[])
	{
		mp[n]=1;

		for(auto i: adj[n])
		{
			if(mp[i]==0)
			{
				dfs(i,adj);

			}
		}
		l.push_front(n);
	}
	bool canFinish(int V, vector<vector<int>>&adj) {


		vector<int> vect[V];

		for(int i=0;i<adj.size();i++)
			vect[adj[i][0]].push_back(adj[i][1]);
		
		
		for(int i=0;i<V;i++)
			mp[i]=0;
		for(int i=0;i<V;i++)
			if(mp[i]==0)
				dfs(i,vect);

			int index=0;
			

			for(auto i : l)
			{
				mp[i]=index;
				index++;
			}

			bool ans=true;
			for(int i=0;i<adj.size();i++)

				if(mp[adj[i][0]]>=mp[adj[i][1]])
					ans=false;
				


				return ans;

			}
		};