/*
Same Tree
leetcode 100

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
			
			if(!(isSameTree(p->right,q->right)))
				return false;
			if(!(isSameTree(p->left,q->left)))
				return false;
		}
		else
			return false;
		
		return true;
		
	}
};