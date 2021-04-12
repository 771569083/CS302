#include"init.h"

void *reader(int *buffer){
    // Reader should read the value of buffer
    // Reader cannot start to work when there is any writer working
    // You should implement this using semaphore
    sem_wait(&rc);
    if (readcount ==0 )
    {
      sem_wait(&db);
    }
    // You should output this just after this thread gets semaphore
    printf("Reader gets sem\n");
    readcount+=1;
    sem_post(&rc);
    // you should output this just before this thread releases the semaphore
    printf("Reader reads %d and releases\n", *buffer); 
    sem_wait(&rc);
    readcount-=1;
    if (readcount ==0 )
    {
      sem_post(&db);
    }
    sem_post(&rc);
}

