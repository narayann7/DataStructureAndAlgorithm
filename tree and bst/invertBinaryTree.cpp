/*
Invert Binary Tree

leetcode 226
*/
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    
    
    if(root==NULL)
      return root;
    
    if((root->left==NULL&&root->right==NULL))
      return root;
    
    if(root->left!=NULL&&root->right!=NULL)
    {
      auto temp= root->left;
      root->left=root->right;
      root->right=temp;   
    }
    else if(root->left==NULL&&root->right!=NULL)
    {
      root->left=root->right;
      root->right=NULL;
    }
    else if(root->left!=NULL&&root->right==NULL)
    {
      
      root->right=root->left;
      root->left=NULL;
    }
    
    if(root->left!=NULL)
     root->left=invertTree(root->left);
   
   
   if(root->right!=NULL)
     root->right=invertTree(root->right);
   
   
   return root;
   
 }
};