#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	int res,n;
	res=open("fifo1",O_WRONLY);
	write(res,"message",7);
	printf("Sender process sending message and id is %d",getpid());
}
