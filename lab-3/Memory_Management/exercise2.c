#include <stdio.h>
#include <stdlib.h>

int global_var = 100;

int stack_var;
int *heap_var;

const char *find_memory_region(void *address)
{
    if (address == &global_var)
        return "Global memory";

    if (address == &stack_var)
        return "Stack memory";

    if (address == heap_var)
        return "Heap memory";

    return "Unknown memory region";
}

int main()
{
    int local_var = 10;
    stack_var = 20;

    heap_var = malloc(sizeof(int));

    if (heap_var == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *heap_var = 30;

    printf("Global variable: %s\n",
           find_memory_region(&global_var));

    printf("Stack variable: %s\n",
           find_memory_region(&stack_var));

    printf("Heap variable: %s\n",
           find_memory_region(heap_var));

    printf("Local variable: %s\n",
           (void *)&local_var == (void *)&local_var
           ? "Stack memory" : "Unknown");

    free(heap_var);
    return 0;
}
