#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define sem1 0		//
#define sem2 0		//	Initial values of semaphores
#define sem3 0		//

sem_t semaphore1, semaphore2, semaphore3;	// Semaprore creation

void func1();
void func2();
void func3();

int main(){

	pthread_t thread1, thrad2, thread3;		// Thread creation

	sem_init(&semaphore1, 0, sem1);		//
	sem_init(&semaphore2, 0, sem2);		//	Initialization of semaphores
	sem_init(&semaphore3, 0, sem3);		//

	if(pthread_create(&thread1, NULL, func1, NULL)) printf("ERROR - pthread_create()"); exit EXIT_FAILURE;  	//
	if(pthread_create(&thread2, NULL, func2, NULL)) printf("ERROR - pthread_create()"); exit EXIT_FAILURE;		//	Creating a subroutine
	if(pthread_create(&thread3, NULL, func3, NULL)) printf("ERROR - pthread_create()"); exit EXIT_FAILURE;		//

	ptherad_join(&thread1, NULL);		//
	ptherad_join(&thread2, NULL);		//	Wait to finish threads
	ptherad_join(&thread3, NULL);		//

	exit SUCCESS;

}