// Sys_Call.c

// System Call Tracer and Mode Switch Demonstrator
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>
#include <time.h>


// System Call Tracer 
void trace_system_calls() {
    // Process ID system call
    printf("getpid() system call:\n");
    pid_t pid = getpid();
    printf("   PID: %d\n", pid);
    
    // Resource usage system call
    printf("\ngetrusage() system call:\n");
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("   User time: %ld.%06ld\n", 
           usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("   System time: %ld.%06ld\n", 
           usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    
    // System information call
    printf("\nsysinfo() system call:\n");
    struct sysinfo info;
    sysinfo(&info);
    printf("   Free memory: %lu KB\n", info.freeram / 1024);
    printf("   Number of processes: %d\n", info.procs);  
    }
    
// Mode Switch Demonstration   
void mode_switching() {
    printf("Running in user mode. Performing some simple mathematical calculations. \n");
    int result = 0;
    for (int i = 0; i < 1000; i++) {
        result += i * i;	 	   }
    printf("   Calculation result: %d\n", result);   
    
    // Perform a system call that triggers mode switch
    printf("\nSwitching to kernel mode by executing nanosleep() system call\n");
    
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 100000000; // 100ms

    // nanosleep is a system call that requires kernel intervention
    nanosleep(&ts, NULL);
    printf("\nReturned to user mode\n");   }

int main() {
    printf("\n___System Call Examples___\n");
    trace_system_calls();
    printf("\n___User/Kernel Mode Switching Example___\n");
    mode_switching();
    return 0;   
    }
