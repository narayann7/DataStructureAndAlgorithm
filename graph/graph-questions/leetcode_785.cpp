//785. Is Graph Bipartite?

class Solution {
public:
	map<int,int> mp;

	bool dfs(int current , int parent ,vector<vector<int>>& graph,int color)
	{
		mp[current]=color;

		for(auto i : graph[current])
		{
			if(mp[i]==0)
			{
				bool key = dfs(i,current,graph,3-color);

				if(key==false)
					return false;
			}
			else if(i!=parent&&color==mp[i])
				return false;
		}


		return true;


	}

	bool isBipartite(vector<vector<int>>& graph) {


		for(int i=0;i<graph.size();i++)
			mp[i]=0;

		for(int i=0;i<graph.size();i++)
		{
			if(mp[i]==0)
			{
				bool key=dfs(i,-1,graph,1);
				if(key==false)
					return false; 
			}

		}
		return true;

	}
};



/*
breakdown

normally check for cyclic graph are not Bipartite
then check for the color , when 2 node have equal color then it is not  Bipartite



class Solution {
public:
	map<int,int> mp;

	bool dfs(int current , int parent ,vector<vector<int>>& graph,int color)
	{
		mp[current]=color;

		for(auto i : graph[current])
		{
			if(mp[i]==0)
			{
				bool key = dfs(i,current,graph,3-color);

				if(key==false)//continue the loop till false comes in nested fuction
					return false;
			}
			else if(i!=parent&&color==mp[i]) 
				return false;

	
			i!=parent , as the graph is bidirectional  than every node will have its parent as edge

			color is equal to mp[i]
			which mean it is same , which mean it is not bipartite


		
		}


		return true;


	}

	bool isBipartite(vector<vector<int>>& graph) {


		for(int i=0;i<graph.size();i++) // making all node as 0 which mean not visited , 1 means color 1 , 2 means color 2
			mp[i]=0;

		for(int i=0;i<graph.size();i++) // this for loop help when the graph is in peices it have more than 1 components
		{
			if(mp[i]==0)
			{
				bool key=dfs(i,-1,graph,1); //contine the loop till false comes
				if(key==false)
					return false; 
			}

		}
		return true;

	}
};


*/