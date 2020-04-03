#include<stdio.h>
#include<conio.h>

struct Process
{
	int process_id;
	int burst_time;
};

void sorting(struct Process temp[] ,  int n)
{
	int a;
	int i , j ;
	temp[n].burst_time=9999;
	for(j= 0 ; j < n; j++)
	{
		for(i = 0 ; i<=j ; i++)
		{
			if(temp[i].burst_time > temp[i+1].burst_time)
			{
			a = temp[i+1].burst_time;
			temp[i+1].burst_time = temp[i].burst_time;
			temp[i].burst_time = a;
			}
		}
	}
	
}


void processWaitTime( struct Process arr[] , int n , int wt[])
{
	int i;
	
	wt[0] = 0; // initializing the 'process 1' waiting time as 0. 
	for(i = 1 ; i< n ; i++)
	{
		wt[i] = arr[i-1].burst_time + wt[i-1];
	}
	
}

void turnAroundTime(struct Process arr[] , int n , int wt[] , int tat[])
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		tat[i] = wt[i] + arr[i].burst_time; 
	}
}

void averageTime(struct Process arr[] , int n)
{
	int wt[n] , tat[n],i ;
	
	processWaitTime(arr , n , wt); //function call 
	
	turnAroundTime(arr , n , wt , tat) ; //function call
	
	printf("priority \t          Process\t       Burst Time\t        Waiting Time\t       Turn Around Time\n ");
	
	for(i = 0 ; i< n ; i++){
		printf(" %d \t             %d \t              %d \t                %d \t     %d\n" ,i+1, arr[i].process_id,arr[i].burst_time,wt[i] , tat[i]);}
	
}



int main()
{  
int w;
printf("ENTER 1 TO RUN THE CODE 2 TO EXIT :");
printf("      ");
//printf("ENTER 2 TO EXIT");
scanf("%d",&w);
if(w==1)
{

   int i,z,j;

	label:
  	
	  
	printf("enter the no of processes:-");
	scanf("%d",&z);
	if(z<=0)
	{
		printf("error no of process must be >1 :");
		printf("         ");
		printf("press 3 to enter back :");
		scanf("%d",&j);
		goto label;
	}
	struct Process arr[z];
	for( i=0;i<z;i++)
	{
		printf("process  %d:-",i+1);
		printf("    ");
		printf("enter process id:");
		scanf("%d",&arr[i].process_id);
		x:
		printf("enter brust time: ");
		
		scanf("%d",&arr[i].burst_time);
		if(arr[i].burst_time<=0)
		{
			printf("------error invalid brust time------------");
			goto x;
		}
	}
	int n = sizeof(arr) / 	sizeof(arr[0]);
	sorting(arr,n);
	averageTime(arr , n) ;

	 // function call
	 
}
	return 0;	
}
