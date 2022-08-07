347. Top K Frequent Elements

class Solution {
public:
	vector<int> topKFrequent(vector<int>& v, int k) {

		map<int,int>mp;
		for(auto i : v){
			mp[i]++;
		}

		vector<int>ans;
		while(k--)
		{
			int max=INT_MIN;
			int temp;
			for(auto i : mp){

				if(max<i.second)
				{
					max=i.second;
					temp=i.first;

				}

			}

			ans.push_back(temp);
			mp.erase(temp);


		}

		return ans;
	}
};