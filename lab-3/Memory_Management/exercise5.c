#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>

#define CHILDREN 3
#define ITERATIONS 5

typedef struct {
    int counter;
    sem_t lock;
} SharedData;

int main(int argc, char *argv[])
{
    int use_lock = 0;

    if (argc > 1 && argv[1][0] == '1')
        use_lock = 1;

    SharedData *shared = mmap(
        NULL, sizeof(SharedData),
        PROT_READ | PROT_WRITE,
        MAP_SHARED | MAP_ANONYMOUS, -1, 0
    );

    if (shared == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }

    shared->counter = 0;

    if (sem_init(&shared->lock, 1, 1) == -1)
    {
        perror("sem_init");
        munmap(shared, sizeof(SharedData));
        return 1;
    }

    printf("Lock: %s\n", use_lock ? "ON" : "OFF");
    fflush(stdout);

    for (int i = 0; i < CHILDREN; i++)
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            perror("fork");
            return 1;
        }

        if (pid == 0)
        {
            for (int j = 0; j < ITERATIONS; j++)
            {
                if (use_lock)
                    sem_wait(&shared->lock);

                // Critical section
                int temp = shared->counter;
                usleep(10000);
                shared->counter = temp + 1;

                if (use_lock)
                    sem_post(&shared->lock);

                usleep(1000);
            }

            _exit(0);
        }
    }

    for (int i = 0; i < CHILDREN; i++)
        wait(NULL);

    printf("Expected counter: %d\n",
           CHILDREN * ITERATIONS);
    printf("Actual counter: %d\n", shared->counter);

    sem_destroy(&shared->lock);
    munmap(shared, sizeof(SharedData));

    return 0;
}
