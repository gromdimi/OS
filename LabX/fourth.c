#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    pid_t pid;
    int fd;
    char pid_str[20];


    fd = open("pids.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }


    pid = fork();
    if (pid == -1) {
        perror("fork");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        sprintf(pid_str, "Child PID: %d\n", getpid());
       
        if (write(fd, pid_str, strlen(pid_str)) == -1) {
            perror("write child");
            close(fd);
            exit(EXIT_FAILURE);
        }
        printf("Child process wrote its PID to the file.\n");
        close(fd);
        exit(EXIT_SUCCESS);
    } else {
        
        sleep(1);
        
        
        sprintf(pid_str, "Parent PID: %d\n", getpid());
        
        if (write(fd, pid_str, strlen(pid_str)) == -1) {
            perror("write parent");
            close(fd);
            exit(EXIT_FAILURE);
        }
        printf("Parent process wrote its PID to the file.\n");
        
        // Wait for child to finish
        wait(NULL);
        close(fd);
    }

    return 0;
}
