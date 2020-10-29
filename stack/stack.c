#include<stdio.h>
#include<stdlib.h>


int stack[100],size,top=-1;

void push(void);
void pop(void);
void display(int[],int);


int main()
{
    int choice,m,ret;
    printf("\n ENTER THE SIZE OF STACK:");
    scanf("%d",&size);
        printf("\nSTACK OPERATIONS ");
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
        do
         {
        printf("\n ENTER YOUR CHOICE :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display(stack,top);
                break;
            }
            
            case 4:
            {
                printf("\n\t EXIT POINT ");
                exit(100);
            }
        }
    }
    while(choice!=4);
    return 0;
}
//code contributed by: narayan
//git: narayann7
//email: laxminarayanreddy432@gmail.com
void push()
{
    int temp;
    if(top>=size-1)
    {
        printf("\n\tSTACK OVERFLOW\n");

    }
    else
    {
        printf(" ENTER THE VALUE TO BE PUSHED :");
        scanf("%d",&temp);
        top++;
        stack[top]=temp;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t STACK UNDERFLOW\n");
    }
    else
    {
        printf("\n\t THE POPPED ELEMENT IS %d",stack[top]);
        top--;
    }
}
void display(int stack[],int top)
{
    if(top==-1)
    {
        printf("\n THE STACK IS EMPTY");

    }
    else
    {
     printf("\n THE STACK IS \n");
     printf("%d<-",stack[top]);
     for(int i=top-1; i>=0; i--)
        printf("\n%d",stack[i]);
    }

}

