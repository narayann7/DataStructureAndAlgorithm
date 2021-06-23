//single linked list  all operation
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void addAtLast() //1
{
    struct node *temp;
    struct node *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the node element = ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        p = head;
        while (p->next != NULL)
            p = p->next;
    }
    p->next = temp;
}
void addAtFront() //2
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the node element=");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
}
int length() //3
{
    int c = 0;
    struct node *p;
    p = head;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
void print() //4
{
    struct node *p;
    p = head;
    if (p == NULL)
        printf("the list is empty\n");
    else
    {
        while (p != NULL)
        {
            printf("%d  ", p->data);
            p = p->next;
        }
    }
}
void delete1() //5
{
    struct node *temp = head;
    struct node *p = head;
    int x;
    printf("enter the postion where the node element should delete \n");
    scanf("%d", &x);
    if (x > length())
    {
        printf("invalid postion\n");
    }
    else if (x == 1)
    {
        temp = head->next;
        head = temp;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        struct node *q;
        int i = 1;
        while (i < (x - 1))
        {
            p = p->next;
            i++;
        }
        q = p->next;
        p->next = q->next;
        q->next = NULL;
        free(q);
    }
}
void addFormPosition() //6
{
    struct node *temp;
    struct node *p = head;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the node element =");
    scanf("%d", &temp->data);
    int x;
    printf("enter the postion where the node element should add\n");
    scanf("%d", &x);
    int i = 1;
    while (i < (x - 1))
    {
        p = p->next;
        i++;
    }
    struct node *q = p->next;
    temp->next = q;
    p->next = temp;
}
//code contributed by: narayan
//git: narayann7
void swap() //7
{
    struct node *q, *r;
    struct node *p = head;
    int x, i = 0;
    printf("enter the postion where the node will shift with the next node\n");
    scanf("%d", &x);
    x = x - 1;
    if (x == length())
        printf("there is no next node fr swaping\n");
    else
    {
        while (i < (x - 1))
        {
            p = p->next;
            i++;
        }
        r = p->next;
        q = r->next;
        r->next = q->next;
        p->next = q;
        q->next = r;
    }
}

void reverse() //8
{
    int t;
    struct node *q = head;
    struct node *p = head;
    int i = 0, j, k;
    j = length() - 1;
    while (i < j)
    {
        k = 0;
        while (k < j)
        {
            q = q->next;
            k++;
        }
        t = p->data;
        p->data = q->data;
        q->data = t;
        i++;
        j--;
        p = p->next;
        q = head;
    }
}
struct node *revprint(struct node *p) //9
{

    if (p == NULL)
        return NULL;
    else
    {

        revprint(p->next);
        printf("%d  ", p->data);
    }
}
//code contributed by: narayan
//git: narayann7
//email: laxminarayanreddy432@gmail.com
void delete2() //10
{
    printf("\nenter the element which you want to delete\n");
    int num;
    scanf("%d", &num);

    struct node *temp = head, *prev, *z = NULL;
    int flag = 0;

    if (head == NULL)
    {
        printf("\tEmpty List\n");
        return;
    }

    while (temp != NULL)
    {
        if (temp->data == num)
        {
            if (temp == head)
                head = head->next;
            else
                prev->next = temp->next;

            flag = 1;
            z = temp;
        }
        else
            prev = temp;

        temp = temp->next;
        if (z != NULL)
            free(z);
        z = NULL;
    }
    if (flag == 0)
        printf("\tDelete Element Not Found\n");
}
int main()
{
    int ch, e, x, l;
    while (1)
    {
        printf("\n");
        printf("\n");
        printf("\n");
        printf("enter 1 for add for first\n");
        printf("enter 2 for add for last\n");
        printf("enter 3 for add for any postion\n");
        printf("enter 4 for length\n");
        printf("enter 5 for print\n");
        printf("enter 6 for delete from index\n");
        printf("enter 7 for swap\n");
        printf("enter 8 for reverse\n");
        printf("enter 9 for print reverse\n");
        printf("enter 10 for delete a element from your choice\n");
        printf("enter 0 for quit\n");
        printf("enter the choice = ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addAtFront();
            break;
        case 2:
            addAtLast();
            break;
        case 3:
            addFormPosition();
            break;
        case 4:
            l = length();
            printf("the length of linked list is  %d\n", l);
            break;
        case 5:
            print();
            break;
        case 6:
            delete1();
            break;
        case 7:
            swap();
            break;
        case 8:
            reverse();
            break;
        case 9:
            revprint(head);
            break;
        case 10:
            delete2();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("invalid\n");
        }
    }
}
