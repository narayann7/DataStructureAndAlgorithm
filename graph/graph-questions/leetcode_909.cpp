/*

909. Snakes and Ladders

shortest path from source unweighted graph

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	int bfs(int n,list<int> *l)
	{
		map<int,int> mp;

		for(int i =0;i<(n*n);i++)
			mp[i]=INT_MAX;
		mp[0]=0;

		queue<int> q;

		q.push(0);

		while(!q.empty())
		{
			int search=q.front();

			for(auto i:l[search])
			{
				if(mp[i]==INT_MAX)
				{
					q.push(i);
					mp[i]=mp[search]+1;
				}
			}
			q.pop();
		}
		for(auto i : mp)
		{
			cout<<i.first<<"--> "<<i.second<<"\n";
		}
		for(int i =0;i<n*n;i++)
		{

			cout<<i<<"--> ";
			for(auto j:l[i])
				cout<<j<<" , ";
			cout<<endl;
		}

		return mp[(n*n)-1];

	}
	int snakesAndLadders(vector<vector<int>>& board) {

		int n=board.size();

		list<int> *l;

		l=new list<int>[n*n];

		int arr[n*n];

		int ii=n-1,jj=0;
		bool flag=true;

		for(int i=0;i<n*n;i++)
		{
			if(board[ii][jj]==-1)
				arr[i]=i;
			else
				arr[i]=board[ii][jj]-1;

			if(flag)
				jj++;
			else
				jj--;


			if(jj==n||jj==-1)
			{
				ii--;

				if(flag)
					jj--;
				else
					jj++;
				flag=!flag;

			}

		}


		for(int i=0;i<n*n;i++)
		{
			if(i+1<n*n)
				l[i].push_back(arr[i+1]);
			if(i+2<n*n)
				l[i].push_back(arr[i+2]);
			if(i+3<n*n)
				l[i].push_back(arr[i+3]);
			if(i+4<n*n)
				l[i].push_back(arr[i+4]);
			if(i+5<n*n)
				l[i].push_back(arr[i+5]);
			if(i+6<n*n)
				l[i].push_back(arr[i+6]);
		}

		return bfs(n,l);
	}
};

int main()
{

	vector<vector<int>> v={
		{-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1},
		{-1,35,-1,-1,13,-1},
		{-1,-1,-1,-1,-1,-1},
		{-1,15,-1,-1,-1,-1},

	};


	Solution s;

	int xx=s.snakesAndLadders(v);

	cout<<xx;


}


