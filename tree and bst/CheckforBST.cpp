//gfg
//only the code part

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return true if the given tree is a BST, else return false
vector<int> infixLoopc(Node *root)
{
    stack<Node *> s;
    Node *temp = root;
    vector<int> v;

    while (s.empty() == false || temp != NULL)
    {
        while ((temp != NULL))
        {
            /* code */
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();
        v.push_back(temp->data);

        temp = temp->right;
    }
    return v;
}

bool isBST(Node *root)
{

    // Your code here

    vector<int> v;
    v = infixLoopc(root);

    int i, f = 0;
    for (i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1] || v[i] == v[i + 1])
        {
            f = 1;
            break;
        }
    }
    if (f == 1)
        return false;
    else
        return true;
}