//gfg
//only the logic part

/* Structure for tree and linked list

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

// This function should return head to the DLL
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

Node *bToDLL(Node *root)
{
    // your code here
    vector<int> v = infixLoopc(root);
    int i;
    Node *root1;
    Node *tail;
    for (i = 0; i < v.size(); i++)
    {
        int x;
        x = v[i];
        Node *r = newNode(x);
        if (i == 0)
        {
            root1 = r;
            tail = r;
        }
        else
        {
            tail->right = r;
            r->left = tail;
            tail = tail->right;
        }
    }
    return root1;
}