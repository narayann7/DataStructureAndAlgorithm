class Solution {
    bool is_valid(TreeNode *root , long long mini  , long long maxi)
    {
        if(!root) return 1;
        if(root->val > mini && root->val < maxi)
            return is_valid(root->left ,mini , root->val) && is_valid(root->right , root->val , maxi);
        else
            return 0;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right) return 1;
        long long maxi = LONG_MAX;
        long long mini = LONG_MIN;
        return is_valid(root , mini , maxi);
    }
};
