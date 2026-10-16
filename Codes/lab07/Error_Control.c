/*
مطالعه آزاد:
والد با استفاده از توابع خاصی، وضعیت خاتمه یافتن فرزند را چک کرده و بر اساس آن پیغام مناسب چاپ می نماید
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    int stat;
    
    if (pid == 0) {
        printf("Child proc will run ls command.\n");
        execlp("ls", "ls", "--invalid-option", NULL);  //replce "--invalid-option" with a valid switch and check the results
        return 1;  // Error code = 1    } 
    else {
        printf("Waiting for child Process to finish...\n");
        // Receives the exact status of child process
        waitpid(pid, &stat, 0);
       
        if (WIFEXITED(stat)) {   //investigats child's exit status
            int exit_code = WEXITSTATUS(stat);
            
            if (exit_code == 0) {     printf("Child Process ran and exited Successfully \n");
            } else {
                printf("Child Process encountered Some Error!");
            }
        }         
        printf("\nParent process terminating.\n");
    }
    
    return 0;
}
// try out other functions : WIFSTOPPED(stat), WSTOPSIG(stat), WIFSIGNALED(stat), WTERMSIG(stat)
