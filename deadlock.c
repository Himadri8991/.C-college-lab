#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *fun1();
void *fun2();
pthread_mutex_t f,s;
int main()
{
	pthread_mutex_init(&f,NULL);
	pthread_mutex_init(&s,NULL);
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,fun1,NULL);
	pthread_create(&thread2,NULL,fun2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("Thread joined inside main programm");
	
}
void *fun1()
{
	printf("Thread 1 is trying to accuire mutex1 \n");
	pthread_mutex_lock(&f);
	printf("Thread 1 accuired mutex1 \n");
	sleep(1);
	printf("Thread 1 is trying to accuire mutex2 \n");
	pthread_mutex_lock(&s);
	printf("Thread 1 accuired mutex2 \n");
	pthread_mutex_unlock(&f);
	pthread_mutex_unlock(&s);
	
}
void *fun2()
{
	printf("Thread 2 is trying to accuire mutex2 \n");
	pthread_mutex_lock(&s);
	printf("Thread 1 accuired mutex2 \n");
	sleep(1);
	printf("Thread 2 is trying to accuire mutex1 \n");
	pthread_mutex_lock(&f);
	printf("Thread 1 accuired mutex1 \n");
	pthread_mutex_unlock(&f);
	pthread_mutex_unlock(&s);
}
