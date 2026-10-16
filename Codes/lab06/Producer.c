// producer.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

// flag variables
volatile sig_atomic_t ready_for_data = 0;
volatile sig_atomic_t data_processed = 0;

// Handler for consumer ready signal
void consumer_ready_handler(int sig) {
    ready_for_data = 1;
    printf("Producer: Consumer is ready to receive data.\n\t  Insert an Integer number as data: ");
}

// Handler for data processing confirmation
void data_processed_handler(int sig) {
    data_processed = 1;
    printf("Producer: Consumer confirmation received.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <consumer_pid>\n", argv[0]);
        return 1;
    }
    
    pid_t consumer_pid = atoi(argv[1]);
    
    printf("Producer PID: %d \n", getpid());
    printf("Consumer PID: %d\n", consumer_pid);
    
    // Register signal handlers
    struct sigaction sa_ready, sa_processed;
    
    // Handler for SIGUSR1 (consumer ready)
    memset(&sa_ready, 0, sizeof(sa_ready));
    sa_ready.sa_handler = consumer_ready_handler;
    sigaction(SIGUSR1, &sa_ready, NULL);
    
    // Handler for SIGUSR2 (data processed)
    memset(&sa_processed, 0, sizeof(sa_processed));
    sa_processed.sa_handler = data_processed_handler;
    sigaction(SIGUSR2, &sa_processed, NULL);
    
    
    // Wait for consumer ready signal
    printf("Producer: Waiting for consumer to be ready.\n");
    while (!ready_for_data) {
        pause(); // Wait for signal
    }
    
    // Produce data
    // In reality, shared memory or pipe would be used to Send data to consumer
    int data_packet;
    scanf("%d", &data_packet);

    
    // Send "data ready" signal
    kill(consumer_pid, SIGUSR1); 
    printf("Producer: Data Ready signal sent. Waiting for processing confirmation from consumer.\n");
    
    // Wait for processing confirmation
    while (!data_processed) {
        pause();
    }

    return 0;
}
