#include<stdio.h>

void sort(int arrival_time[], int processes[], int burst_time[], int n){
	int a;
	for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            if (arrival_time[i] > arrival_time[j]){
            	a = processes[i];
            	processes[i] = processes[j];
            	processes[j] = a;
            	a = burst_time[i];
            	burst_time[i] = burst_time[j];
            	burst_time[j] = a;
            }
        } 
    }

}

void findWaitingTime(int processes[], int n, int bt[], int wt[]){
	wt[0] = 0;
	for(int i = 1; i < n; i++){
		wt[i] = bt[i-1] + wt[i-1];
	}
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
	for(int i = 0; i < n; i++){
		tat[i] = bt[i] + wt[i];
	}
}

void findAvgTime(int processes[], int n, int bt[]){
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(processes, n, bt, wt);

	findTurnAroundTime(processes, n, bt, wt, tat);

	printf("Processes    Burst Time    Waiting time    Turn around time\n");

	for(int i = 0; i < n; i++){
		total_wt += wt[i];
		total_tat += tat[i];
		printf("  %d", processes[i]);
		printf("             %d", bt[i]);
		printf("                %d", wt[i]);
		printf("             %d\n", tat[i]);
	}

	int s = (float)total_wt/(float)n;
	int t = (float)total_tat/(float)n;
	printf("Average waiting time: %d\n", s);
	printf("Avergae turnaround time: %d\n", t);
}


int main(){
	int processes[] = { 1, 2, 3};//{2, 1, 3}
	int n = sizeof processes/sizeof(processes[0]);

	int arrival_time[] = { 5, 1, 10}; //
	//{1, 5, 10}
	//{1, 0, 2}
	int burst_time[] = { 10, 5, 8};//{5, 10, 8}
	sort(arrival_time, processes, burst_time, n);

	findAvgTime(processes, n, burst_time);
	return 0;
}