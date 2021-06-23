//gfg
//logic part only

vector<int> levelOrder(struct Node* node)
{
    vector <int> res;
     // Base Case
    if (node == NULL)  return res;
    // Create an empty queue for level order tarversal
    queue<Node *> q;

    // Enqueue Root and initialize height
    q.push(node);

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        Node *node = q.front();
        res.push_back (node->data);
        q.pop();

        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);

        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
    return res;
}

