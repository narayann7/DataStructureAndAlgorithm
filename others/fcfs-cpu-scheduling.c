#include <stdio.h>


int findMin(int *arr,int size){

	int min=1000;
	int index=-1;


	for (int i = 0; i < size; ++i)
	{
		
		if(arr[i]<min)
		{
			min=arr[i];
			index=i;
		}
	}



	return index;


}


int main()
{
	int size=5;
	printf("Enter no of process \n");
	scanf("%d",&size);


	int arrival_time[size];
	int arrival_time2[size];


	int brust_time[size];
	int hash[size];
	int completion_time[size];
	int completion_time2[size];
	int turn_around_time[size];
	int waiting_time[size];

	printf("Enter arrival_time \n");


	for (int i = 0; i < size; ++i)
	{
		int n;
		scanf("%d",&n);

		arrival_time[i]=n;
		arrival_time2[i]=n;
		
	}
	printf("Enter brust_time \n");


	for (int i = 0; i < size; ++i)
	{
		int n;
		scanf("%d",&n);

		brust_time[i]=n;
		
	}




	for (int i = 0; i < size; ++i)
	{


		int min_index =findMin(arrival_time,size);
		completion_time[i]=brust_time[min_index];
		hash[i]=min_index;

		arrival_time[min_index]=1000;


	}



	for (int i = 1; i < size; ++i)
	{

		if(arrival_time2[hash[i]]>=completion_time[i-1])
		{
			completion_time[i]=arrival_time2[hash[i]]+completion_time[i];

		}
		else
		{
			completion_time[i]=completion_time[i-1]+completion_time[i];

		}

	}

	int avg_completion_time=0,avg_turn_around_time=0, avg_waiting_time=0;
	for (int i = 0; i < size; ++i)
	{


		completion_time2[i]=completion_time[hash[i]];
		avg_completion_time+=completion_time2[i];


		turn_around_time[i]=completion_time2[i]-arrival_time2[i];
		avg_turn_around_time+=turn_around_time[i];


		waiting_time[i]=turn_around_time[i]-brust_time[i];
		avg_waiting_time+=waiting_time[i];

	}




	printf("process\tAT\tBT\tCT\tTAT\tWT\tRT\t\n");

	for (int i = 0; i < size; ++i)
	{

		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),arrival_time2[i],brust_time[i],completion_time2[i],turn_around_time[i],waiting_time[i],waiting_time[i] );


	}

	printf("average turn_around_time = %d\n",avg_turn_around_time );
	printf("average avg_waiting_time = %d\n",avg_waiting_time );
	printf("average avg_completion_time = %d\n",avg_completion_time );




	return 0;
}


/*

2
0
2
3
4



2
1
3
5
4


*/