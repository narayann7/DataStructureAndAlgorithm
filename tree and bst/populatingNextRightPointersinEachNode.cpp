/*
Populating Next Right Pointers in Each Node
leetcode 117

*/

class Solution {
public:
	Node* connect(Node* root) {
		if(root==NULL)
			return root;
		
		queue<Node*> q;
		
		q.push(root);
		while(!q.empty())
		{
			int size=q.size();
			auto e1=q.front();
			if(e1->left)
				q.push(e1->left);
			if(e1->right)
				q.push(e1->right);
			q.pop();
			
			for(int i=2;i<=size;i++)
			{
				auto element=q.front();
				e1->next=element;
				e1=element;
				if(element->left)
					q.push(element->left);
				if(element->right)
					q.push(element->right);
				q.pop();
				
			}
			e1->next=NULL;
		}
		
		return root;
	}
};