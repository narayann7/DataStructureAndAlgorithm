/*

Binary Tree Right Side View 
leetcode 199

*/

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {

		vector<int> v;
		if(root==NULL)
			return v;

		queue<TreeNode*> q;
		q.push(root);

		while(!q.empty())
		{

			int size=q.size();
			for(int i=1;i<=size;i++)
			{
				TreeNode * n=q.front();
				if(i==size)
					v.push_back(n->val);

				if(n->left!=NULL)
					q.push(n->left);

				if(n->right!=NULL)
					q.push(n->right);

				q.pop();
			}
		}

		return v;

	}
};