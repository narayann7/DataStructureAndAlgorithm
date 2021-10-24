#include <stdio.h>
#include <stdlib.h>

struct node
{
   float coef;
   int expo;
   struct node *link;
};

struct node *insert_sp(struct node *start, float co, int ex)
{
   struct node *ptr, *tmp;
   tmp = (struct node *)malloc(sizeof(struct node));
   tmp->coef = co;
   tmp->expo = ex;
   tmp->link = NULL;

   /*list empty or exp of new item is greater than first one then it added at the begining*/
   if (start == NULL || ex > start->expo)
   {
      tmp->link = start;
      start = tmp;
   }
   /*adding the new item at its proper position to make the polynomial sorted based on exponents.*/
   else
   {
      ptr = start;
      while (ptr->link != NULL && ptr->link->expo >= ex)
         ptr = ptr->link;
      tmp->link = ptr->link;
      ptr->link = tmp;
   }
   return start;
}

struct node *insert_end(struct node *start, float co, int ex)
{
   struct node *ptr, *tmp;
   tmp = (struct node *)malloc(sizeof(struct node));
   tmp->coef = co;
   tmp->expo = ex;
   tmp->link = NULL;

   if (start == NULL) /*If list is empty*/
   {
      start = tmp;
   }
   else /*Insert at the end of the list*/
   {
      ptr = start;
      while (ptr->link != NULL)
         ptr = ptr->link;
      ptr->link = tmp;
   }
   return start;
}

struct node *create(struct node *start)
{
   int i, n, ex;
   float co;
   printf("Enter the number of terms : ");
   scanf("%d", &n);
   for (i = 1; i <= n; i++)
   {
      printf("Enter coeficient for term %d : ", i);
      scanf("%f", &co);
      printf("Enter exponent for term %d : ", i);
      scanf("%d", &ex);
      start = insert_sp(start, co, ex);
   }
   return start;
}

void display(struct node *ptr)
{
   if (ptr == NULL)
   {
      printf("Zero polynomial\n");
      return;
   }
   while (ptr != NULL)
   {
      printf("(%.1fx^%d)", ptr->coef, ptr->expo);
      ptr = ptr->link;
      if (ptr != NULL)
         printf(" + ");
      else
         printf("\n");
   }
}

void poly_add(struct node *p1, struct node *p2)
{
   struct node *start3;
   struct node *start4;
   start3 = NULL;

   while (p1 != NULL && p2 != NULL)
   {
      if (start3 == NULL)
      {

         if (p1->expo == p2->expo)
         {
            p1->coef = p1->coef + p2->coef;
            start3 = p1;
            p1 = p1->link;
            p2 = p2->link;
         }
         else if (p1->expo > p2->expo)
         {
            start3 = p1;
            p1 = p1->link;
         }
         else
         {
            start3 = p2;
            p2 = p2->link;
         }
         start4 = start3;
      }
      else
      {
         if (p1->expo == p2->expo)
         {
            p1->coef = p1->coef + p2->coef;
            start3->link = p1;
            p1 = p1->link;
            p2 = p2->link;
            start3 = start3->link;
         }
         else if (p1->expo > p2->expo)
         {
            start3->link = p1;
            p1 = p1->link;
            start3 = start3->link;
         }
         else
         {
            start3->link = p2;
            p2 = p2->link;
            start3 = start3->link;
         }
      }
   }
   if (p1 == NULL)
      start3->link = p2;
   if (p2 == NULL)
      start3->link = p1;

   printf("Added polynomial is : ");
   display(start4);
}

int main()
{
   struct node *start1 = NULL, *start2 = NULL;

   printf("Enter polynomial 1 :\n");
   start1 = create(start1);

   printf("Enter polynomial 2 :\n");
   start2 = create(start2);

   printf("Polynomial 1 is :  ");
   display(start1);
   printf("Polynomial 2 is :  ");
   display(start2);

   poly_add(start1, start2);

   return 0;
}