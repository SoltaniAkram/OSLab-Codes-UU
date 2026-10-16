//sem.c
#include <stdio.h>		// Standard input-output library
#include <pthread.h>		// POSIX thread library
#include <semaphore.h>	// Semaphore library
#include <unistd.h>		// POSIX operating system API

sem_t mutex;

void* thread(void* arg) { 

sem_wait(&mutex);

printf("\n The thread has entered the critical section \n");

sleep(4);

printf("\nExiting thread\n");

sem_post(&mutex);
}

int main() {

sem_init(&mutex, 0, 1);

pthread_t	t1, t2;

pthread_create(&t1, NULL, thread, NULL);
sleep(2);

pthread_create(&t2, NULL, thread, NULL);

pthread_join(t1, NULL);
pthread_join(t2, NULL);

sem_destroy(&mutex);

return 0;
}
