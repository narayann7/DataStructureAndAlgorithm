324. Wiggle Sort II : leetcode

class Solution {
public:
	void wiggleSort(vector<int>& v) {

		if(v.size()==1||v.size()==0)
			return;
		if(v.size()==2){
			if(v[0]>v[1]){
				int temp=v[1];
				v[1]=v[0];
				v[0]=temp;
			}  
			return ;
		}

		int n=v.size();
		vector<int> ans(n);

		sort(v.begin(),v.end());

		int i=1,j=n-1;

		while(i<v.size())
		{
			ans[i]=v[j];
			i+=2;
			j--;

		}
		i=0;
		while(i<v.size())
		{
			ans[i]=v[j];
			i+=2;
			j--;

		}


		for(int i=0 ;i<v.size();i++){
			v[i]=ans[i];
		}


	}
};