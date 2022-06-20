#include<stdio.h>

struct process
{
	int WT,AT,TAT,BT,PT;
};
struct process a[10];
int main()
{
	int i,j,n,t,temp[10],count=0,short_p;
	float avg_tat,avg_wt,total_WT,total_TAT;
	printf("Enter the number of process:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the AT and BT of process[%d]\n",i+1);
		scanf("%d",&a[i].AT);
		scanf("%d",&a[i].BT);
		printf("Enter priority of process[%d]\n",n+1);
		scanf("%d",&a[i].PT);
		temp[i]=a[i].BT;
	}
	a[9].PT=10000;
	for(t=0;count!=n;t++)
	{
		short_p=9;
		for(i=0;i<n;i++)
		{
			if(a[short_p].PT>a[i].PT && a[i].AT<=t && a[i].BT>0)
			{
				short_p=i;
			}
		}
		a[short_p].BT=a[short_p].BT-1;
		if(a[short_p].BT==0)
		{
			count++;
			a[short_p].WT=t+1-a[short_p].AT-temp[short_p];
			a[short_p].TAT=t+1-a[short_p].AT;
			total_WT=total_WT+a[short_p].WT;
			total_TAT=total_TAT+a[short_p].TAT;
		}
	}
	avg_tat=total_TAT/n;
	avg_wt=total_WT/n;
	printf("\nProcess No.\t\tAT\t\tBT\t\tPT\t\tTAT\t\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,a[i].AT,a[i].BT,a[i].PT,a[i].TAT,a[i].WT);
	}
	printf("\n");
	printf("\nAverage TAT:%f",avg_tat);
	printf("\nAverage WT:%f",avg_wt);
	
	return 0;
		
}
