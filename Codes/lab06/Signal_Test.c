// signal_test.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// Signal handler function - called when a signal is received
void signal_handler(int sig) {
    printf("\nSignal received: %d (%s)\n", sig, strsignal(sig));
}

// Display current signal status by reading from /proc filesystem
void print_signal_status() {
    char command[256];
    // Build command to read signal status from /proc
    snprintf(command, sizeof(command), 
             "echo 'Current Signal Status:' && "
             "cat /proc/%d/status | grep -A4 Sig", 
             getpid());
    
    // Execute the command to show signal status
    system(command);
    printf("\n");
}

int main() {
    printf("Signal Handling \n");
    printf("================\n");
    printf("Process ID (PID): %d\n\n", getpid());
    
    // Display initial signal status
    //printf("Initial signal status:\n");
    //print_signal_status();
    
    // Register signal handlers for different signals
    //printf("Registering signal handlers...\n");
    signal(SIGUSR1, signal_handler);  // User-defined signal 1
    signal(SIGUSR2, signal_handler);  // User-defined signal 2
    signal(SIGTERM, SIG_DFL);  // Termination request
    signal(SIGINT, SIG_DFL);   // Interrupt (Ctrl+C)
    
    //printf("Signal handlers registered successfully!\n\n");
    
    // Display status after handler registration
    //printf("Status after handler registration:\n");
    //print_signal_status();
    
    // Instructions for testing
    printf("Ready to receive signals...\n\n");
    printf("TESTING INSTRUCTIONS - Run these in another terminal:\n");
    printf("   Send SIGUSR1:    kill -USR1 %d\n", getpid());
    printf("   Send SIGUSR2:    kill -USR2 %d\n", getpid());
    printf("   Send SIGTERM:    kill -TERM %d\n", getpid());
    printf("   Interrupt:       Press Ctrl+C in this terminal\n");
    printf("   Check status:    cat /proc/%d/status | grep Sig\n\n", getpid());
    
    /*printf("Signal explanations:\n");
    printf("   - SIGUSR1/SIGUSR2: User-defined signals for custom purposes\n");
    printf("   - SIGTERM: Graceful termination request\n");
    printf("   - SIGINT: Interrupt signal (usually from Ctrl+C)\n\n");*/
    
    //printf("Entering signal waiting loop...\n");
    //printf("   (Program will wait here for incoming signals)\n");
    //printf("   (Press Ctrl+C to exit or send SIGTERM to terminate)\n\n");
    
    // Infinite loop to wait for signals
    // pause() suspends the program until a signal is received
    while(1) {
        printf("Waiting for signal...\n");
        pause();  // Wait for any signal
        // Display updated status after each signal
        //print_signal_status();
        
        printf("Signal processed, waiting for next signal...\n\n");
  
    }
    
    return 0;
}
