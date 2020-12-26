//gfg
//only the logicpart

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    int height(struct Node *node)
    {
        struct Node *x = node;
        int a = 0, b = 0;
        if (x != 0)
        {
            a = height(x->left);
            b = height(x->right);

            if (a > b)
                return a + 1;
            else
                return b + 1;

           
        }
    }
};