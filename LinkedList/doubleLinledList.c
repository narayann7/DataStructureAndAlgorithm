#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

struct node *ins_beg(struct node *);
struct node *ins_end(struct node *);

struct node *del_beg(struct node *);
struct node *del_end(struct node *);

void fwd_trav(struct node *);
void bwd_trav(struct node *);

struct node *ins_beg(struct node *head)
{

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the node element=");
    scanf("%d", &temp->info);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head->prev = temp;

        head = temp;
    }

    return head;
}

struct node *ins_end(struct node *head)
{
    struct node *temp;
    struct node *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the node element=");
    scanf("%d", &temp->info);
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
        head = temp;
    else
    {
        p = head;
        while (p->next != NULL)
            p = p->next;
    }
    p->next = temp;

    temp->prev = p;
    return head;
}
void fwd_trav(struct node *head)
{
    struct node *p;
    p = head;
    if (p == NULL)
        printf("the list is empty\n");
    else
    {
        while (p != NULL)
        {
            printf("%d  ", p->info);
            p = p->next;
        }
    }
}

void bwd_trav(struct node *head)
{
    struct node *p;
    p = head;
    if (p == NULL)
        printf("the list is empty\n");
    else
        while (p->next != NULL)
            p = p->next;

    while (p != NULL)
    {
        printf("%d  ", p->info);
        p = p->prev;
    }
}

struct node *del_beg(struct node *head)
{
    struct node *p;

    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        p = head;
        head = head->next;
        head->prev = NULL;
        free(p);
    }
    return head;
}

struct node *del_end(struct node *head)
{
    struct node *p;
    struct node *p1;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        p = head;
        while (p->next->next != NULL)
            p = p->next;

        p->next = NULL;
    }

    return head;
}

int main()
{
    struct node *head = NULL;
    int choice, data, item, pos;

    while (1)
    {
        printf("\n1.Insert at begin\n");
        printf("2.Insert at end\n");
        printf("3.Delete from begin\n");
        printf("4.Delete from end\n");
        printf("5.Forward traverse\n");
        printf("6.Backward traverse\n");
        printf("7.Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = ins_beg(head);
            break;
        case 2:
            head = ins_end(head);
            break;
        case 3:
            head = del_beg(head);
            break;
        case 4:
            head = del_end(head);
            break;
        case 5:
            fwd_trav(head);
            break;
        case 6:
            bwd_trav(head);
            break;
        case 7:
            exit(1);
        default:
            printf("Wrong choice\n");
        } /*End of switch */
    }     /*End of while */
}