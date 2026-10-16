#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
pid_t pid,ppid;
pid = getpid();
ppid=getppid();
printf("PID = %d, PPID = %d \n ", pid, ppid);
return 0;}
