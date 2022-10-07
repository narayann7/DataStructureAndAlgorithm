#include <stdio.h>

int getMinKey(int *a,int *c,int size )
{

int min=100000,m;
for (int i = 0; i <size; i++)
{
if(c[i]==0&&a[i]<min)
{
  min=a[i];
  m=i;
}
}
return m;
}

int main() {
 
int noOfVertex,startVertex;
printf("enter no of Vertex\n");
scanf("%d",&noOfVertex);
printf("enter start Vertex\n");
scanf("%d",&startVertex);

int matrix[noOfVertex][noOfVertex];
int parent[noOfVertex];
int cost[noOfVertex];
int a[noOfVertex];

printf("enter the matrix \n");
for (int i = 0; i < noOfVertex; i++)
{
for (int j = 0; j < noOfVertex; j++)
scanf("%d",&matrix[i][j]);
a[i]=1000000;
cost[i]=0;
}


parent[startVertex-1]=-1;
cost[startVertex-1]=0;
a[startVertex-1]=0;


for (int i = 0; i < noOfVertex-1; i++)
{
int minE=getMinKey(a,cost,noOfVertex);
cost[minE]=1;
for (int j = 0; j < noOfVertex; j++)
{
  if(matrix[minE][j]&&cost[j]==0&&matrix[minE][j]<a[j])
  {
    parent[j]=minE;
    a[j]=matrix[minE][j];

  }
}

}
printf("key parent cost \n ");
int mst=0;
for (int i = 0; i < noOfVertex; i++)
{
mst+=matrix[i][parent[i]];
}

for (int i = 0; i < noOfVertex; i++)
{
parent[i]=parent[i]+1;
}
parent[startVertex-1]=-1;
for (int i = 0; i < noOfVertex; i++)
{
printf("%d   %d   %d ",i+1,parent[i],matrix[i][parent[i]-1]);
printf("\n");
}


printf("the cost of spanning tree : %d",mst);
}




// enter no of Vertex
// 5
// enter start Vertex
// 1
// enter all profits 
// 0 2 0 6 0
// 2 0 3 8 5
// 0 3 0 0 7
// 6 8 0 0 9 
// 0 5 7 9 0

// 0 4 0 0 0 0 0 8 0
// 4 0 8 0 0 0 0 11 0
// 0 8 0 7 0 4 0 0 2
// 0 0 7 0 9 14 0 0 0
// 0 0 0 9 0 10 0 0 0
// 0 0 4 14 10 0 2 0 0
// 0 0 0 0 0 2 0 1 6
// 8 1 1 0 0 0 0 1 0 7
// 0 0 2 0 0 0 6 7 0
