//gfg
//only the logic part
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Should convert tree to its mirror */
Node *mirror1(Node *node)
{
    if (node == NULL)
        return NULL;
    Node *temp;
    Node *temp1;
    temp = mirror1(node->right);
    temp1 = mirror1(node->left);
    node->right = temp1;
    node->left = temp;

    return node;
}

void mirror(Node *node)
{
    
    node = mirror1(node);
}