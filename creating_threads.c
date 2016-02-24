// Notes: Running the program i notice that threads works separately from main programa, so 
// if the main program terminates the thread will terminates too. To avoid that we can mantein 
// the program in infite loop or use pthread_join() to wait for thread terminates. Use pthread_join()
// inside loop notice that threads will execute in order, because after each creation pthread_join()
// will make the for() loop wait until de thread finishes it routine. But this do not happens 
// in practice. Lots of threads are created simultaneously and finishes in the same way. To 
// simulate that pthread_join() is used in the end of main program.


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define N 10	// Number of threads.

void *message(void *threadID);	// Print thread ID

int main(){

	pthread_t thread[N];

	int i;

//	Creates N thread that each one will execute function message in parallel.

	for(i=0; i<N; i++){

		if(pthread_create(&thread[i], NULL, message, (void *)i)){
			printf("ERROR to create thread %d", i); 
			exit (EXIT_FAILURE);
		}

	}

	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	pthread_join(thread[3], NULL);
	pthread_join(thread[4], NULL);
	pthread_join(thread[5], NULL);
	pthread_join(thread[6], NULL);
	pthread_join(thread[7], NULL);
	pthread_join(thread[8], NULL);
	pthread_join(thread[9], NULL);
	
	exit (EXIT_SUCCESS);
}

void *message(void *threadID){

	int tid;
	tid = (int)threadID;
	printf("Thread ID: %d\n", tid);
	pthread_exit(NULL);
}