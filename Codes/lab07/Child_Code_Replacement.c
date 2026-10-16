#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
pid_t pid=fork();
if (pid==0) {
printf("Child proc will run ls command.\n"); 
execlp("ls", "ls","-l",NULL);
return 1; }
else  {
printf("Waiting for child Process to finish.\n\n"); 
wait(NULL); 
printf("\nChild Process just finished. Now terminating the parent Process\n"); }
return 0;}
