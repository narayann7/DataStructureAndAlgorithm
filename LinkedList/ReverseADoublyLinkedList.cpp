//gfg
//only the logic part
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
Node *reverseDLL(Node *head)
{
    //Your code here
    Node *temp;
    Node *p;
    Node *q;
    p = NULL;
    temp = head;
    while (temp != NULL)
    {
        q = temp;
        temp = temp->next;
        q->next = p;
        p = q;
        p->prev = temp;
    }
    return p;
}