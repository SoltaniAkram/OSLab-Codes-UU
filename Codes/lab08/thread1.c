//create a new thread inside the main thread
//run this code several times to observe the order of the threads execution.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to be executed by the new thread
void* thread_function(void* arg) {
printf("Hello from new thread!\n");
return NULL;
}

int main() {
pthread_t thread;
printf("Hello from main thread!\n");

// Create a new thread
pthread_create(&thread, NULL, thread_function, NULL);


// The main program continues while the other thread executes.
printf("Main thread is running parallel with the new thread !\n");

// Wait for the new thread to finish.(ensures that the main thread waits for the new thread to finish before continuing.)
/* args:
thread: The thread identifier.
NULL: A pointer to the return value of the thread (not used here).
*/
pthread_join(thread, NULL) ;

// Only the main thread is running now.
printf("Now, only the main thread is running!\n");
return 0;
}