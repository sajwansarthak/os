#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Parent: Starting program\n");

    pid = fork();  // Creates a child process

    if (pid < 0) {
        // Fork failed
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child: I am going to run 'ls -l' command using exec\n");

        // execlp replaces current process with ls
        execlp("ls", "ls", "-l", NULL);

        // If exec fails
        printf("Exec failed!\n");
    } else {
        // Parent process
        printf("Parent: Waiting for child to finish...\n");
        wait(NULL);
        printf("Parent: Child finished execution.\n");
    }

    return 0;
}
