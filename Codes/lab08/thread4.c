//multi threads, one function, static buffer as shared resource
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 100

// Static buffer
static char buffer[BUFFER_SIZE];

// Function to be called by threads
void* write_to_buffer(void* arg) {
char* str = (char*)arg; //arg is a ptr to string
for (int i = 0; i < BUFFER_SIZE - 1; ++i) {
buffer[i] = str[i % strlen(str)];//fill the buffer with the chars from the arg string: each char of the buffer is set to a char from the str
usleep(100); // Sleep(micro seconds) to simulate real work and increase the chance of context switch to demonstrate concurrency issues in multi threading
}
buffer[BUFFER_SIZE - 1] = '\0'; // set the last char of the buffer to Null terminator, marking the end of the str in the buffer
printf("Buffer content from thread: %s\n", buffer);
return NULL;
}

int main() {
pthread_t thread1, thread2;

// Create two threads
pthread_create(&thread1, NULL, write_to_buffer, "1111111111");
pthread_create(&thread2, NULL, write_to_buffer, "2222222222");

// Wait for both threads to finish
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);

// Print final buffer content
printf("\nFinal buffer content: %s\n", buffer);

return 0;
}

