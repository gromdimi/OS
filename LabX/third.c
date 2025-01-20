#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

void signal_handler(int sig) {
    printf("Child process received signal %d\n", sig);
    exit(0);
}

int main() {
    pid_t pid;


    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        signal(SIGUSR1, signal_handler);
        
       
        printf("Child process with PID %d waiting for signal...\n", getpid());
        while(1) {
            sleep(1);
        }
    } else {
        sleep(1);
        
               printf("Parent process sending SIGUSR1 to child with PID %d\n", pid);
        if (kill(pid, SIGUSR1) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }
        
       
        wait(NULL);
        printf("Parent process has finished waiting for child.\n");
    }

    return 0;
}
