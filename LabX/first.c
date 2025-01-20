#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int i;

    for (i = 0; i < 3; i++) {
        pid = fork();
        
        if (pid < 0) {
            // Periptosi error fork
            perror("Fork failed");
            return 1;
        } else if (pid == 0) {
            
            printf("Child process %d of iteration %d, PID: %d\n", i + 1, i + 1, getpid());
            
        } else {
            
            printf("Parent process, PID: %d, Child PID: %d\n", getpid(), pid);
            
            wait(NULL);
            
            if (i == 2) {
                return 0;
            }
        }
    }

    return 0;
}
