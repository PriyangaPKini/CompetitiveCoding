#include<stdio.h>
#include <stdbool.h>
int c,n;
int time=0;

int count=0;

struct Processes
	{
		int arrivalTime,burstTime, waiting,turnAround,rt,p;
		bool flag;
		int name;
	}process[100];


void fcfs();
void sjf();
void roundRobin();
void priority();
void bsortProcess(struct Processes process[n]);
void display(struct Processes process[n]);
void displayStatus(struct Processes process[n]);

void input(struct Processes process[n]);


void displayStatus(struct Processes process[n])
{
	int j=0;
	for(j=0;j<n;j++)
	{
	    printf("time:%d",time);
	    printf("%s	remaining time:%d name:%d\n", process[j].flag ? "true" : "false"
	            , process[j].rt ,process[j].name);
	}
}

void display(struct Processes process[n])
{
	int j;
	for(j=0;j<n;j++)
	{	
		printf("\nProcess		Arrival Time		Burst Time		Waiting Time		Turn Around Time\n");
    	printf("Process %d:	  %d			  %d	 	 	%d			 %d	\n",process[j].name,process[j].arrivalTime,
    	        process[j].burstTime,process[j].waiting , process[j].turnAround);
	}


}
void input(struct Processes process[n])
{
	int i,j;
	for(i=0;i<n;i++){
		process[i].name=i+1;
		printf("Enter the Arrival time of process %d:",i);
		scanf("%d",&process[i].arrivalTime);
		printf("Enter the Burst time of process %d:",i);
		scanf("%d",&process[i].burstTime);
		process[i].rt=process[i].burstTime;
		process[i].flag=false;



	}
}

void bsortProcess(struct Processes process[n])
{
    int i, j;
    struct Processes temp;
    
    for (i = 0; i < n- 1; i++)
    {
        for (j = 0; j < (n -1-i); j++)
        {
	  
	switch(c)
	{
		case 1:  if (process[j].arrivalTime > process[j + 1].arrivalTime)
            		{
                		temp = process[j];
                		process[j] = process[j + 1];
                		process[j + 1] = temp;
            		} 
			break;
		case 2: if (process[j].burstTime > process[j + 1].burstTime)
            		{
                		temp = process[j];
                		process[j] = process[j + 1];
                		process[j + 1] = temp;
            		} 
			break;
		case 3:  if (process[j].arrivalTime > process[j + 1].arrivalTime)
            		{
                		temp = process[j];
                		process[j] = process[j + 1];
                		process[j + 1] = temp;
            		} 
			break;
        case 4: if (process[j].p > process[j + 1].p)
            {
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }


    }
        }
    }


}
void priority() {
    int i, j, cp = 10, tq = 1;
    time = 0;
    input(process);
    for (i = 0; i < n; i++) {
        printf("\nEnter the priority for process %d:\n", i);
        scanf("%d", &process[i].p);
    }


    bsortProcess(process);
    while (count < n) {
        for (i = 0; i < n; i++) {

            if (process[i].arrivalTime <= time && process[i].rt > 0) {

                time = time + process[i].burstTime;
                process[i].rt = process[i].rt - process[i].burstTime;
                count++;
                printf("\nProcess %d is executing..\n", process[i].name);
                process[i].turnAround = time - process[i].arrivalTime;
                process[i].waiting = process[i].turnAround - process[i].burstTime;
                break;
            }

        }

    }
    display(process);
}

void roundRobin()
{
	//struct Processes process[n];
	int i,j;
	int tq=3;
	input(process);
	
	bsortProcess(process);


    while (true) {
    	for(i=0;i<n;i++) {
            if (process[i].arrivalTime<=time && process[i].rt >0) {

                printf("\nProcess%d is executing...\n", process[i].name);

                process[i].rt -=tq ;

                if (process[i].rt <= 0) {
                    if (process[i].rt < 0) {
                        process[i].rt +=tq;
                        time += process[i].rt;
                        process[i].rt =0;

                    }
                    else {
                        time+=tq;
                    }

                    process[i].flag = true;
                    count++;
                    printf("%d", count);
                    process[i].turnAround = time - process[i].arrivalTime;
                    process[i].waiting = process[i].turnAround - process[i].burstTime;


                }
                else {

                time += tq;
                }


            }
            else if (count == n) {
            break;
            }
            //displayStatus(process);
    	}
    	if(count==n){
            display(process);
            break;
    	}
    }
}

void sjf()
{

	int i,j,bsum=0;
	input(process);
	
	bsortProcess(process);
	i=0;
	while(count<=n)
	{	
		if(process[i].arrivalTime<=bsum)
		{
		printf("\nProcess%d is executing...\n",process[i].name);
		bsum+=process[i].burstTime;
		process[i].turnAround=bsum-process[i].arrivalTime;
		process[i].waiting=process[i].turnAround-process[i].burstTime;
		count++;
		
		}
		i=(i+1)%n;
	}

	display(process);


}



void fcfs()
{
	struct Processes process[n];
	int i,j,bsum=0;
	input(process);

	bsortProcess(process);

	for (i = 0; i < n; ++i)
	{	
		printf("Process%d is executing...",process[i].name);
		bsum+=process[i].burstTime;
		process[i].turnAround=bsum-process[i].arrivalTime;
		process[i].waiting=process[i].turnAround-process[i].burstTime;
	}
	display(process);
		
}


void main()
{

printf("Enter the number of processes:");
scanf("%d",&n);
printf("Choose your Cpu scheduling algorithm:\n1.FCFS\n2.SJF\n3.ROUND ROBIN\n4.PRIORITY\n");
scanf("%d",&c);
switch(c)
{
	case 1: fcfs();
		break;
	case 2: sjf();
		break;
	case 3: roundRobin();
		break;
    case 4:	priority();
        break;
    default:printf("Invalid choice!!\n");
        break;
}
}

			


