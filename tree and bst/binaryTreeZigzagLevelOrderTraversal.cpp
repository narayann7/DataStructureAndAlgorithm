/*
Binary Tree Zigzag Level Order Traversal

leetcode 103

*/


class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		
		vector<vector<int>> ans;
		if(root==NULL)
			return ans;
		
		queue<TreeNode*> q;
		bool flag=true;
		
		q.push(root);
		while(!q.empty())
		{
			
			int size=q.size();
			vector<int> v;
			
			for(int i=1;i<=size;i++)
			{
				TreeNode* element = q.front();
				v.push_back(element->val);
				
				if(element->left!=NULL)
					q.push(element->left);
				if(element->right!=NULL)
					q.push(element->right);   
				
				q.pop();
			}
			if(flag==false)
				reverse(v.begin(),v.end());
			flag=!flag;
			
			ans.push_back(v);
			
		}
		return ans;
	}
};