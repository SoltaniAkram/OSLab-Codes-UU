#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
pid_t pid=fork();
if (pid==0) {
printf("Child proc PID: %d, PPID: %d \n", getpid(), getppid()); 
usleep(100);
}
else  {
printf("Parent proc PID: %d, Child process PID: %d \n", getpid(), pid); 
wait(NULL); 
printf("Child Process just finished. Now terminating the parent Process\n"); }
return 0;}
