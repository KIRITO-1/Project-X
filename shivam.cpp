#include<stdio.h>
#include<stdlib.h>

int Process;
struct lottery
{
	int a[100];
}s[100];

int main()
{
	//NUMBER OF PROCESS
	printf("Enter the number of process:-\n");
	scanf("%d",&Process);
	int a[Process],c[Process],random;
	int i,j,pr[Process],k,sum1;
	int sum=0;
	
	//PRIORITY INPUT HIGHER THE NUMBER HIGHER THE PRIORITY
	printf("HIGHER THE NUMBER HIGHER THE PRIORITY\n");
	for(i=0;i<Process;i++)
	{
		printf("Enter the priority number of process %d:\t",i+1);
		scanf("%d",&pr[i]);
		sum+=pr[i];
	}
	sum1=sum;
	
	//ASSIGNING LOTTERY TICKETS HIGHER PRIORITY WILL GET MORE TICKETS
	for(i=0;i<Process;i++)
	{
		for(j=0;j<pr[i];j++)
		{
			s[i].a[j]=sum;
			sum=sum-1;
		}
	}
	for(i=0;i<Process;i++)
	{
		printf("\nProcess %d has tikcet number: ",i+1);
		for(j=0;j<pr[i];j++)
		{
			printf("%d ",s[i].a[j]);
		}
	}
	
	//Intial Cpu time 0
	for(i=0;i<Process;i++)
	{
		c[i]=0;
	}
	
	//LOTTERY SCHEDULING ASSIGNING CPU TIME TO PROCESS
	for(k=0;k<50;k++)
	{
		random=((rand()+1)%sum1+1);
		for(i=0;i<Process;i++)
		{
			for(j=0;j<pr[i];j++)
			{
				if(random==s[i].a[j])
				{
					c[i]=c[i]+20;
				}
			}
		}
	}
	printf("\n");
	
	//PRINTING CPU TIME
	for(i=0;i<Process;i++)
	{
		printf("\nProcess %d has %d CPU time\t",i+1,c[i]);
	}
	return 0;
}
