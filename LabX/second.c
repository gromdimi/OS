#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t cpid;
    char buf;


    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork  child process
    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {   
       
        close(pipefd[1]);

       
        if (read(pipefd[0], &buf, 1) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("Child process received message: %c\n", buf);

       
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    } else {           
       
        close(pipefd[0]);

       
        if (write(pipefd[1], "A", 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        printf("Parent process sent message: A\n");

       
        close(pipefd[1]);

        // Wait for child to finish
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}
