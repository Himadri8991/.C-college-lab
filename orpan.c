#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main()
{
	pid_t q;
	q=fork();
	if(q==0)
	{
		sleep(30);
		printf("Child having pid %d \n",getpid());
		printf("parent having pid %d \n",getppid());
	}
	else
	{
		sleep(50);
		printf("parent having pid %d \n",getpid());
		printf("Child having pid %d \n",q);
	}
	
}
