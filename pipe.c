#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int fd[2],n;
	char buff[100];
	pid_t q;
	pipe(fd);
	q=fork();
	if(q==0)
	{
		printf("Parent send message to child and id is %d \n",getpid());
		write(fd[1],"Hello\n",6);
	}
	else
	{
		printf("child received message &  id is %d \n",getppid());
		n=read(fd[0],buff,100);
		write(1,buff,100);
	}
}
