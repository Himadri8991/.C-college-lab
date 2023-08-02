#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
int main()
{
	int res;
	res=mkfifo("fifo1",0777);
	printf("named pipe craeted");
}
