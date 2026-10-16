#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
int fd[2];
char message[] = "Hello from parent";
char buffer[100];
pipe(fd);

pid_t pid=fork();
if (pid==0) {
close(fd[1]);
read(fd[0], buffer, sizeof(buffer));
printf("Child proc received: %s.\n", buffer); 
close(fd[0]); }
else  {
close(fd[0]);
write (fd[1], message, strlen(message)+1); 
close(fd[1]);
wait(NULL); }
return 0;}
