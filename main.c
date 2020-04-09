#include<stdio.h>

int main(){

	int burst_time[10] = {0}, arrival_time[10] = {0}, turn_around_time[10] = {0}, waiting_time[10] = {0}, ct[10] = {0}, temp, p[10];
	int n, sum = 0;
	float total_Turn_Around_Time = 0, total_Waiting_Time = 0;
	int i, j, k;
	
	
	printf("Enter number of processes	");
	scanf("%d",&n);

	printf("Enter arrival time and burst time for each process\n\n");
	for(i=0;i<n;i++)
	{

		printf("Arrival time of process %d	", i+1);
		scanf("%d", &arrival_time[i]);
		
		printf("Burst time of process[%d]	", i+1);
		scanf("%d", &burst_time[i]);
		
		printf("\n");
	}
	for(i=0; i<n-1 ; i++)
    {
        for(j=i+1 ; j<n ; j++)
        {
            if(burst_time[i]>burst_time[j])
            {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
		
	//calculate completion time of processes 	

	for(j=0 ; j<n ; j++)
	{
		sum += burst_time[j];
		ct[j] += sum;
	}

	//calculate turnaround time and waiting times 

	for(k = 0 ; k<n ; k++)
	{
		turn_around_time[k] = ct[k] - arrival_time[k];
		total_Turn_Around_Time += turn_around_time[k];
	}

	
	for(k = 0 ; k<n ; k++)
	{
		waiting_time[k] = turn_around_time[k] - burst_time[k];
		total_Waiting_Time += waiting_time[k];
	}
	
	printf("Solution: \n\n");
	printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");
	
	for(i = 0 ; i<n ; i++)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, arrival_time[i], burst_time[i], ct[i], turn_around_time[i], waiting_time[i]);
	}
		
	printf("\n\nAverage Turnaround Time = %f\n", total_Turn_Around_Time/n);
	printf("Average WT = %f\n\n", total_Waiting_Time/n);
	
	return 0;
}
