// Notes: This is the program related to the quest 1 of lista_C.
// Running the program to each situacion we heva:
//
// a) Deadlock
// b) Deadlock
// c) Deadlock
// d) Deadlock


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define MIN_EXEC 6	// Number of times that threads will be executed
#define N 3 		// Number of threads
#define sem1 0		//
#define sem2 0		// Initial values of semaphores
#define sem3 3		//

sem_t semaphore[N];	// Semaphores creation

void *routine(void *ID);	//  Function to be executed by thread (in this case operation like 
							//	increase and decrease semaphore and print thread ID).

int main(){

	// pthread_t thread1, thrad2, thread3;		// Thread ID
	pthread_t thread[N];
	int i;

	sem_init(&semaphore[0], 0, sem1);		//
	sem_init(&semaphore[1], 0, sem2);		//	Initialization of semaphores
	sem_init(&semaphore[2], 0, sem3);		//

	for(i=0; i<N; i++){
		if(pthread_create(&thread[i], NULL, routine, (void *)i)){
			printf("ERROR to create thread: %d\n", i);
			exit (EXIT_FAILURE);
		}
	}


	pthread_join(thread[0], NULL);		//
	pthread_join(thread[1], NULL);		//	Wait to finish threads
	pthread_join(thread[2], NULL);		//

	exit (EXIT_SUCCESS);

}

void *routine(void *ID){

	int thread_func;
	int j, k, l;
	thread_func = (int)ID;

	switch(thread_func){

//	Process 1 to be executed by thread 0

		case 0:	
			for(j=0; j<MIN_EXEC; j++){			
				sem_wait(&semaphore[0]);
				sem_wait(&semaphore[0]);
				sem_wait(&semaphore[0]);	
				printf("Thread: %d\n", thread_func);
				sem_post(&semaphore[1]);	
			}	
		break;

//	Process 2 to be executed by thread 1

		case 1:		
			for(k=0; k<MIN_EXEC; k++){
				sem_wait(&semaphore[1]);
				printf("Thread: %d\n", thread_func);
				sem_post(&semaphore[2]);
				sem_post(&semaphore[0]);
			}
		break;

// Process 3 to be executed by thread 2
		case 2:
			for(l=0; l<MIN_EXEC; l++){
				sem_wait(&semaphore[2]);
				sem_wait(&semaphore[2]);
				sem_wait(&semaphore[2]);	
				printf("Thread: %d\n", thread_func);
				sem_post(&semaphore[1]);
				sem_post(&semaphore[1]);
			}
		break;

		default:
			printf("ERROR!\n");
	}

}

