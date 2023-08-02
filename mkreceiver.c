#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int res,n;
	char buff[100];
	res=open("fifo1",O_RDONLY);
	n=read(res,buff,100);
	printf("Reader process reading having pid %d",getpid());
	printf("Data received by receiver having pid %d",getpid(),buff);
	
}
