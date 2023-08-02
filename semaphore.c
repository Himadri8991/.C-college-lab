#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
void *fun1();
void *fun2();
int shared=1;
sem_t s;
int main()
{
	sem_init(&s,0,1);
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,fun1,NULL);
	pthread_create(&thread2,NULL,fun2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("The final vaule of shared is %d: ",shared);
	
}
void *fun1()
{
	sem_wait(&s);
	int x;
	x=shared;
	printf("Thread2 local value updation X as %d\n",x);
	x++;
	sleep(1);
	shared=x;
	printf("Value updated by shared as %d \n",shared);
	sem_post(&s);
}
void *fun2()
{
	sem_wait(&s);
	int y;
	y=shared;
	printf("Thread2 local value updation X as %d\n",y);
	y--;
	sleep(1);
	shared=y;
	printf("Value updated by shared as %d \n",shared);
	sem_post(&s);
}
