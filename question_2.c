#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_OPS 7

struct asm_operations
{
  int pos;
  char *asm_ops[NUM_OPS];
};

struct asm_operations asmx;
 

char *instructions[] ={"MOV","PUSH","POP","IN","OUT","ADD","SUB","DIV","MUL","DEC","INC","CMP","NOT","AND","OR","XOR","CALL","JNP","JE","JZ"};

sem_t semaphore1;
sem_t semaphore2;

void *write();
void *read();

int main(){
    pthread_t tid1, tid2;
    int j;
     

    sem_init(&semaphore1, 0, 1); // (&semaphore, fork , valor do S)
    sem_init(&semaphore2, 0, 0);

    if(pthread_create(&tid1, NULL, write, NULL)){
      printf("\n ERROR creating thread 1");
      exit(1);
    }

    if(pthread_create(&tid2, NULL, read, NULL)){
      printf("\n ERROR creating thread 2");
      exit(1);
    }

    if(pthread_join(tid1, NULL)){    /* wait for the thread 1 to finish */    
      printf("\n ERROR joining thread");
      exit(1);
    }

    if(pthread_join(tid2, NULL)){        /* wait for the thread 2 to finish */    
      printf("\n ERROR joining thread");
      exit(1);
    }
    pthread_exit(NULL);
}

void *write(){

    while(asmx.pos < NUM_OPS -1){
      sem_wait(&semaphore1);
      asmx.asm_ops[asmx.pos] = instructions[asmx.pos];
      printf("Escrever\n");       
      printf("%s\n", asmx.asm_ops[asmx.pos]);
      sem_post(&semaphore2);
    } 
}

void *read(){

    while(asmx.pos < NUM_OPS){
      sem_wait(&semaphore2); //testa se e 0, se nao for decrementa
      if(asmx.asm_ops[asmx.pos] != instructions[asmx.pos]){
        printf("ERRO!\n");
        exit (EXIT_FAILURE);
      }
      printf("Ler\n");
      printf("%s\n", asmx.asm_ops[asmx.pos]);
      asmx.pos = asmx.pos + 1;
      sem_post(&semaphore1);  
    }  
}