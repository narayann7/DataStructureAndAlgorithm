/*

 Symmetric Tree
 leetcode 101

*/



class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		
		if(p==NULL&&q==NULL)
			return true;
		if(p!=NULL&&q==NULL)
			return false;
		if(p==NULL&&q!=NULL)
			return false;
		
		if(p->val==q->val)
		{
			
			if(!(isSameTree(p->right,q->left)))
				return false;
			if(!(isSameTree(p->left,q->right)))
				return false;
		}
		else
			return false;
		
		return true;
		
	}
	bool isSymmetric(TreeNode* root) {
		if(root==NULL)
			return true;
		
		return isSameTree(root->right,root->left);
		
		
	}
};