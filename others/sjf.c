#include<stdio.h>
#include<stdlib.h>

typedef struct process{
	int id, at, bt, ct, tat, wt;
}process;

void sort_process_at(process *P, int N){
	int i, j;
	process temp;
	for(i=0; i<N-1; i++){
		for(j=0; j<N-i-1; j++){
			if(P[j].at > P[j+1].at){
				temp = P[j];
				P[j] = P[j+1];
				P[j+1] = temp;
			}
			
			if(P[j].at == P[j+1].at){
				if(P[j].bt > P[j+1].bt){
					temp = P[j];
					P[j] = P[j+1];
					P[j+1] = temp;
				}
			}
		}
	}
}

void sort_process_bt(process *P, int s, int e){
	int i, j;
	process temp;
	for(i=0; i<e-s; i++){
		for(j=s; j<e-i; j++){
			if(P[j].bt > P[j+1].bt){
				temp = P[j];
				P[j] = P[j+1];
				P[j+1] = temp;
			}
		}
	}
}

void calc_ct(process *P, int N){
	int i, end;
	for(i=0; i<N; i++){
		end = i+1;
		if (i==0 || P[i].at > P[i-1].ct){
			P[i].ct = P[i].at + P[i].bt;
		}
		else{
			P[i].ct = P[i-1].ct + P[i].bt;
		}
		
		
		while (end < N-1 && P[i].ct >= P[end].at){
			end++;
		}
		sort_process_bt(P, i+1, end);
		
	}
}

void calc_tat_wt(process *P, int N){
	int i;
	for(i=0; i<N; i++){
		P[i].tat = P[i].ct - P[i].at;
		P[i].wt = P[i].tat - P[i].bt;
	}
}

void display(struct process *P, int N){	
	int i, j;
	process temp;
	/*for(i=0; i<N-1; i++){
		for(j=0; j<N-i-1; j++){
			if(P[j].id > P[j+1].id){
				temp = P[j];
				P[j] = P[j+1];
				P[j+1] = temp;
			}
		}
	}*/
	printf("Process | Arrival time | Burst time | Completion time | Turn around time | Waiting time\n");
	for(i=0; i<N; i++){
	printf("  P%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n", P[i].id, P[i].at, P[i].bt, P[i].ct, P[i].tat, P[i].wt);
	}
}

int main(){
	int N, i;
	printf("Enter the no. of processes: ");
	scanf("%d", &N);
	process *P = (process*)malloc(N*sizeof(process));
	for(i=0; i<N; i++){
		P[i].id = i+1;
		printf("Enter arrival time of process P%d: ", i+1);
		scanf("%d", &P[i].at);
		printf("Enter burst time of process P%d: ", i+1);
		scanf("%d", &P[i].bt);
	}
	
	sort_process_at(P, N);
	
	calc_ct(P, N);

	calc_tat_wt(P, N);
	
	display(P, N);
	
	float total_tat=0, total_wt=0;
	for(i=0; i<N; i++){
		total_tat += P[i].tat;
		total_wt += P[i].wt;
	}
	printf("Avg. Turnaround time: %.2f\n", total_tat/N);
	printf("Avg. Waiting time: %.2f\n", total_wt/N);

	return 0;
}
