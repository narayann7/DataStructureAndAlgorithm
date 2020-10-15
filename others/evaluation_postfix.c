#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"operation.h"
#include<ctype.h>
int evaluation_postfix(char *postfix)
{
    int i;
    stack s;
    s.data=(char*)malloc(sizeof(char)*100);
    s.top=-1;
    int a;
    int b,c;
    for(i=0;postfix[i]!='\0';i++)
    {
       if(isdigit(postfix[i]))
       {
       a=postfix[i]-48;
       push(&s,a);
       }
       else
       {
           b=pop(&s);
           c=pop(&s);
           switch(postfix[i])
           {
               case '+':
               push(&s,b+c);
               break;
               case '-':
               push(&s,b-c);
               break;
               case '*':
               push(&s,b*c);
               break;
               case '/':
               push(&s,b/c);
               break;
           }
       }
       
    }
    return s.data[s.top];

}
int main()
{
    char postfix[100];
    printf("\n enter the postfix exp\n");
    scanf("%s",postfix);
    printf("%d",evaluation_postfix(postfix));
}