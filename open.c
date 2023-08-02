#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	int fd1,fd2,n;
	char buff[100];
	fd1=open("f1",O_RDONLY);
	fd2=open("f2",O_WRONLY|O_APPEND);
	n=read(fd1,buff,100);
	write(fd2,buff,n);
}
