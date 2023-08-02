#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

int main()
{
	pid_t q;
	q=fork();
	if(q==0)
	{
		sleep(2);
		printf("Child having pid %d \n",getpid());
		printf("parent having pid %d \n",getppid());
	}
	else
	{
		wait(NULL);
		sleep(6);
		printf("parent having pid %d \n",getpid());
		printf("Child having pid %d \n",q);
	}
	
}
