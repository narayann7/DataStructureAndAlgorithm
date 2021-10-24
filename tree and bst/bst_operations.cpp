#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

} node;

node *addNode(node *root, int num) //recursion
{
    if (root == NULL)
    {
        // root=(node*)malloc(sizeof(node*));
        root = new node;
        root->data = num;
        root->left = NULL;
        root->right = NULL;
    }
    else

    {
        if (num > root->data)
            root->right = addNode(root->right, num);
        else
        {
            root->left = addNode(root->left, num);
        }
    }
    return root;
}
node *addNode2(node *root, int num) //loop
{
    node *n;
    node *temp;
    node *parent;
    n->data = num;
    n->left = n->right = NULL;
    if (root == NULL)
    {
        root = n;
    }
    else
    {
        temp = root;
        while (temp != NULL)
        {
            parent = temp;
            if (num > temp->data)
                temp = temp->right;
            else
                temp = temp->left;
        }
        if (num > parent->data)
            parent->right = n;
        else
            parent->left = n;
    }
    return root;
}

void infix(node *root) //infix using recursion
{
    if (root != NULL)
    {
        infix(root->left);
        cout << root->data << " ";
        infix(root->right);
    }
}
void infixLoop(node *root)
{
    stack<node *> s;
    node *temp = root;

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
        cout << temp->data << " ";

        temp = temp->right;
    }
}


int main()
{
    int ch,i;

    node *root = NULL;
    int n;vector <int> v;
    while (true)
    {
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter";

            cin >> n;
            root = addNode(root, n);
            break;
        case 2:
            infix(root);
            break;
        case 3:
            infixLoop(root);
            break;
        case 4:
            cout << "enter";

            cin >> n;
            root = addNode2(root, n);
            break;
            case 5:
           


        default:
            break;
        }
    }
}