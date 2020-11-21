#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
 
{
	int data;
	struct Node *next;
}node;
 
node *head=NULL ,*tail=NULL;
 void insertAtBegin()
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	printf("Enter the node value : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(tail==NULL)
	head=tail=temp;
	else
	{
		temp->next=head;
        head=temp;
        
	}
	
	tail->next=head;

  
}
 void insertAtEnd()
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	printf("Enter the node value : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(tail==NULL)
	head=tail=temp;
	else
	{
		tail->next=temp;
		tail=temp;
	}
	
	tail->next=head;

  
}
void deleteAtBegin()
{
	node *temp=head;
	if(head==NULL)
		printf("\nUnderflow :");
	else
	{
		if(head==tail)
		{
            printf("the deleted element is %d",head->data);
			head=tail=NULL;
		}
		else
		{
            printf("the deleted element is %d",head->data);
			head=head->next;
			tail->next=head;
		}
 
	temp->next=NULL;
	free(temp);
	}
}
void deleteAtEnd()
{

    if (head == NULL)
        printf("\nUnderflow :");
    else
    {
        if (head == tail)
        {
            printf("\n%d", head->data);
            head = tail = NULL;
        }
        else
        {
            node *temp = head;
            node *temp1;
            while (temp != tail)//it will point to n-1 element
            {
                temp1 = temp;
                temp = temp->next;
            }
            tail = temp1;
            tail->next = head;
            printf("the deleted element is %d",temp->data);
            free(temp);
        }
    }
}
	
void display()
{
	node *temp;
	if(head==NULL)
		printf("Empty\n");
	else
	{
		printf("the elements are %d,",head->data);//only printing last element as head so in the loop we can use head as loop break condition 
		for(temp=head->next;temp!=head;temp=temp->next)
			printf("%d,",temp->data);
            printf("\n");
	}
}


int main()
{
   while(1)
   {
    printf("\n 1 to insert the element from begin : ");
    printf("\n 2 to insert the element from end: ");
	printf("\n 3 to delete the element from begin : ");
	printf("\n 4 to delete the element from end : ");
	printf("\n 5 to display the queue : ");
	printf("\n 6 to exit from main : ");
	printf("\nEnter your choice : ");

    int ch;
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:
        insertAtBegin();
        break;
        case 2:
        insertAtEnd();
        break;
        case 3:
        deleteAtBegin();
        break;
        case 4:
        deleteAtEnd();
        break;
        case 5:
        display();
        break;
        case 6:
        exit(0);
        break;
        default:
        printf("invaid option");
    }
   }
}













