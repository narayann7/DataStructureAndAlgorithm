//gfg
//only the logic part
/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
int kthLargest(Node *root, int K)
{
    //Your code here
    vector<int> v = infixLoopc(root);
    reverse(v.begin(), v.end());
    return v[K - 1];
}