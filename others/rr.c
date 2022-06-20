#include<stdio.h>
int main()
{
	int i,y,NOP,sum=0,quant,count=0,wt=0,tat=0,at[10],bt[10],temp[10];
	float avg_tat,avg_wt;
	printf("Enter total number of process:");
	scanf("%d",&NOP);
	y=NOP;
	for(i=0;i<NOP;i++)
	{
		printf("Enter arrival time of process[%d]\n",i+1);
		printf("Arrival Time:\n");
		scanf("%d",&at[i]);
		printf("Burst Time:\n");
		scanf("%d",&bt[i]);
		temp[i]=bt[i];
	}
	printf("Enter the time interval:");
	scanf("%d",&quant);
	printf("\nProcess\t\tAT\t\tBT\t\tTAT\t\tWT");
	printf("\n-----------------------------------------------------------------");
	for(sum=0,i=0;y!=0;)
	{
		if(temp[i]<=quant && temp[i]>0)
		{
			sum+=temp[i];
			temp[i]=0;
			count=1;
		}
		else if(temp[i]>0)
		{
			temp[i]=temp[i]-quant;
			sum=sum+quant;
		}
		if(temp[i]==0 && count==1)
		{
			y--;
			printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d",i+1,at[i],bt[i],sum-at[i],sum-at[i]-bt[i]);
			wt=wt+sum-at[i]-bt[i];
			tat=tat+sum-at[i];
			count=0;
		}
		if(i==NOP-1)
		{
			i=0;
		}
		else if(at[i+1]<=sum)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}
	avg_tat=tat*1.0/NOP;
	avg_wt=wt*1.0/NOP;
	printf("\nAverage Turn Around Time:%f\n",avg_tat);
	printf("Average Waiting Time:%f\n",avg_wt);	
	return 0;
}
