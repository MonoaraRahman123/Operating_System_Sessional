#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Process ID (PID): %d\n", getpid());
    printf("Parent Process ID (PPID): %d\n", getppid());

    while (1)
    {
        sleep(2);
        printf("Current Parent PID: %d\n", getppid());
        fflush(stdout);
    }

    return 0;
}
