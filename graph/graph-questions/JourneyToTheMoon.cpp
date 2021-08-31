#include<bits/stdc++.h>
using namespace std;
#define ll long long


class sloution{

public:
	map<ll,list<ll>> mp;

	map<ll,ll>hash;

	int countGlobal=0;

	vector<ll> v;

	ll fact(ll n)
	{
		ll ans=1;
		for(ll i=2;i<=n;i++)
			ans*=i;
		return ans;
	}


	ll combination(ll a,ll b)
	{
		return fact(a)/(fact(b)*fact(a-b));
	}

	void addEdge(ll x,ll y)
	{
		mp[x].push_back(y);
		mp[y].push_back(x);
	}

	void dfs(ll start)
	{
		hash[start]=1;
		countGlobal++;

		for(auto i:mp[start])
		{
			if(hash[i]==0)
				dfs(i);
		}
	}


	ll solve(ll n)
	{
		for(auto i:mp)
			hash[i.first]=0;


		ll count=0;
		for(auto i:mp)
		{
			if(hash[i.first]==0)
			{
				dfs(i.first);
				count++;
				v.push_back(countGlobal);
				countGlobal=0;
			}
		}
		ll ans=combination(n,2);


		for(auto i : v)
			if(i>=2)
				ans-=combination(i,2);


			return ans;
		}
	};



	int main()
	{
		ll n,p;
		cin>>n>>p;
		sloution s;
		
		while(p--)
		{
			ll a,b;
			cin>>a>>b;
			s.addEdge(a,b);
		}


		cout<<s.solve(n);

	}

	