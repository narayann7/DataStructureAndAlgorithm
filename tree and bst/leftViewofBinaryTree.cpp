/*

Binary Tree left Side View 
geekforgeeks

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

				if(n->right!=NULL)
					q.push(n->right);

				if(n->left!=NULL)
					q.push(n->left);

				q.pop();
			}
		}

		return v;

	}
};