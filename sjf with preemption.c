#include<stdio.h>
void Sorting();
struct sjf
{
	int processno,arr_time,burst_time,wait_time,tar_time,complete_time;
	int flag;
	
}process[100];

void main()
{
	int i,t=0,b_t=0,peak;
	int a[10],n;
	float wait_time=0,taround_time=0,avg_w_t=0,avg_taround_time=0;
	
	printf("Enter the number of process:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		process[i].processno=i+1;
		printf("\nEnter details for Process %d process:",i+1);
		printf("\nEnter Arrival time: ");
		scanf("%d",&process[i].arr_time);
		printf("Enter Burst time: ");
		scanf("%d",&process[i].burst_time);
		process[i].flag=0;
		b_t=b_t+process[i].burst_time;		
	}
	Sorting();
	for(i=0;i<n;i++)
	{
		a[i]=process[i].burst_time;
		
	}
	process[9].burst_time=9999;
	for(t=process[0].arr_time;t<b_t+1;t++)
	{
		peak=9;
		for(i=0;i<n;i++)
		{
			if(process[i].arr_time<=t && process[i].burst_time<process[peak].burst_time && process[i].flag!=1)
			{
				peak=i;
			}
			if(process[peak].burst_time==0 &&process[i].flag!=1)
			{
				process[i].flag=1;
				process[peak].complete_time=t;
				process[peak].burst_time=9999;
				printf("P%d complete in %d\n",process[i].processno,process[peak].complete_time);
			}
		}
		(process[peak].burst_time)--;
	}
	for(i=0;i<n;i++)
	{
		process[i].tar_time=(process[i].complete_time)-(process[i].arr_time);
		avg_taround_time=avg_taround_time+process[i].tar_time;
		process[i].wait_time=((process[i].tar_time)-a[i]);
		avg_w_t=avg_w_t+process[i].wait_time;
	}
	printf("PNO\tAT\tCT\tA\tWT\t\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\n",process[i].processno,process[i].arr_time,process[i].complete_time,process[i].tar_time,process[i].wait_time);
		
	}
	printf("Average Turn around Time: %f\t\n\n",avg_taround_time);
	printf("Average Waiting Time :\t %f\t\n",avg_w_t);	
	
}

void Sorting()
{
	struct sjf p;
	int i,j,n;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(process[i].arr_time>process[j].arr_time)
			{
				p=process[i];
				process[i]=process[j];
				process[j]=p;
			}
		}
	}
}
