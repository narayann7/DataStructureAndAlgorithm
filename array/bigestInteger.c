bigest integer

#include <stdio.h>
#include<string.h>
int arr[300];
int len=1;

int cr=0;
void faac(int n)
{
	for( int i=0;i<len;i++)
	{
		int o=0;
		o=n*arr[i]+cr;
		arr[i]=o%10;
		cr=o/10;
	}
	while(cr)
	{
		arr[len]=cr%10;
		cr=cr/10;
		len++;
	}
}


int main()
{ int i;
arr[0]=1;
int n;
scanf("%d",&n);
for(i=2;i<=n;i++)
	faac(i);
for(i=len-1;i>=0;i--)
	printf("%d",arr[i]);
}


