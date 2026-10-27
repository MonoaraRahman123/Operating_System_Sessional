#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        // Child process: write to file
        int fd = open("data.txt",
                      O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (fd < 0)
        {
            perror("open");
            _exit(1);
        }

        const char message[] = "Hello from child process!\n";

        if (write(fd, message, sizeof(message) - 1) < 0)
        {
            perror("write");
            close(fd);
            _exit(1);
        }

        close(fd);
        printf("Child: Data written to file.\n");
        fflush(stdout);
        _exit(0);
    }
    else
    {
        // Parent process: wait for child
        int status;
        waitpid(pid, &status, 0);

        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
        {
            printf("Child process failed.\n");
            return 1;
        }

        printf("Parent: Child finished.\n");

        // Read the file
        int fd = open("data.txt", O_RDONLY);

        if (fd < 0)
        {
            perror("open");
            return 1;
        }

        char buffer[100];
        ssize_t n;

        while ((n = read(fd, buffer, sizeof(buffer))) > 0)
            write(STDOUT_FILENO, buffer, n);

        if (n < 0)
            perror("read");

        close(fd);
    }

    return 0;
}
