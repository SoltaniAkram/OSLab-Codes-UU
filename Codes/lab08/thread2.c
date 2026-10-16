// get an integer argument from the user and pass it to the thread. Return the result from the thread function to the main thread
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to be executed by the new thread
void* thread_function(void* arg) {
int number = *((int*)arg); // Cast the argument to an integer pointer and dereference it
int* result = malloc(sizeof(int)); // Allocate memory for the result
*result = number * 2; // Example computation: double the number
return (void*)result; // Return the result as a void pointer
}

int main() {
pthread_t thread; // Declare a thread identifier
int number;       // The integer to be passed to the thread
int* thread_result; // Pointer to store the result from the thread

// Get the integer from the user
printf("Enter an integer: ");
scanf("%d", &number);

// Create a new thread that will run 'thread_function'
pthread_create(&thread, NULL, thread_function, &number) ;

// Wait for the thread to finish and get the result
pthread_join(thread, (void**)&thread_result) ; //thread_result is a ptr, &thread_result: address of the ptr, void* is a ptr that could poinbt to any data type. void** : casts &thread_result to a ptr to ptr of unspecified type. use case: where u need to change the original pointer, e.g. allocate memory for it.
//(void**)&thread_result) is used to convert the address of a ptr variable into a generic pointer-to-pointer type, allowing for more flexible manipulation of the original pointer.

// Print the result
printf("Thread returned value: %d\n", *thread_result);

// Free the allocated memory
free(thread_result);

return 0;
}
