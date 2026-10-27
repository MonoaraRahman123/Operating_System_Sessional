#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int a, b;

    printf("Enter two integers: ");

    if (scanf("%d %d", &a, &b) != 2)
    {
        printf("Invalid input!\n");
        return 1;
    }

    char operations[] = {'+', '-', '*', '/'};

    for (int i = 0; i < 4; i++)
    {
        int fd[2];

        if (pipe(fd) == -1)
        {
            perror("pipe");
            return 1;
        }

        pid_t pid = fork();

        if (pid < 0)
        {
            perror("fork");
            return 1;
        }

        if (pid == 0)
        {
            close(fd[0]);

            double result = 0;
            int valid = 1;

            switch (operations[i])
            {
                case '+':
                    result = (double)a + b;
                    break;

                case '-':
                    result = (double)a - b;
                    break;

                case '*':
                    result = (double)a * b;
                    break;

                case '/':
                    if (b == 0)
                        valid = 0;
                    else
                        result = (double)a / b;
                    break;
            }

            // Send validity and result to parent
            write(fd[1], &valid, sizeof(valid));
            write(fd[1], &result, sizeof(result));

            close(fd[1]);
            _exit(0);
        }
        else
        {
            close(fd[1]);

            int valid;
            double result;
            ssize_t n1 = read(fd[0], &valid, sizeof(valid));
            ssize_t n2 = read(fd[0], &result, sizeof(result));

            close(fd[0]);

            int status;
            waitpid(pid, &status, 0);

            if (n1 != sizeof(valid) || n2 != sizeof(result) ||
                !WIFEXITED(status) || WEXITSTATUS(status) != 0)
            {
                printf("Child process failed.\n");
                return 1;
            }

            if (operations[i] == '/')
                printf("Division: ");

            if (!valid)
                printf("Cannot divide by zero.\n");
            else
                printf("%d %c %d = %.2f\n",
                       a, operations[i], b, result);
        }
    }

    return 0;
}
