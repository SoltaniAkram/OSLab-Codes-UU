// Consumer.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>


volatile sig_atomic_t data_ready = 0;

// Handler for data ready signal
void data_ready_handler(int sig) {
    data_ready = 1;
    printf("Consumer: Data is prepared by producer.\n");
}


int main() {
    printf("Consumer PID: %d\n", getpid());
    /* Find producer (in reality, other methods would be used such as Config files, Named Pipes, Sockets, D-Bus, …) This is just for testing */
    pid_t producer_pid;
    printf("Enter producer PID: ");
    scanf("%d", &producer_pid);

    // Register signal handlers
    struct sigaction sa_data;
    
    // Handler for SIGUSR1 (data ready) 
    memset(&sa_data, 0, sizeof(sa_data));
    sa_data.sa_handler = data_ready_handler;
    sigaction(SIGUSR1, &sa_data, NULL);
   
    // Send ready signal to producer
    kill(producer_pid, SIGUSR1);
    printf("Consumer: Ready signal sent. waiting for data preparation by Producer.\n");
    
    // Wait for data
    while (!data_ready) {
        pause();
    }
    
    // Process data
    printf("Consumer: Press Enter to process data. \n");
    getchar();
    getchar();
    sleep(1); // Simulate processing
    
    
    // Send processing confirmation
    kill(producer_pid, SIGUSR2);
    printf("Consumer: Data Processed and confirmation sent to Producer.\n");
    
    return 0;
}