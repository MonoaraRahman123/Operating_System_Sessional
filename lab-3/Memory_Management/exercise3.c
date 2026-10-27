#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage:\n");
        printf("./exercise3 reverse STRING\n");
        printf("./exercise3 count STRING\n");
        printf("./exercise3 add NUM1 NUM2\n");
        printf("./exercise3 multiply NUM1 NUM2\n");
        return 1;
    }

    if (strcmp(argv[1], "reverse") == 0)
    {
        if (argc != 3)
        {
            printf("Usage: ./exercise3 reverse STRING\n");
            return 1;
        }

        int len = strlen(argv[2]);

        printf("Reversed string: ");

        for (int i = len - 1; i >= 0; i--)
            printf("%c", argv[2][i]);

        printf("\n");
    }
    else if (strcmp(argv[1], "count") == 0)
    {
        if (argc != 3)
        {
            printf("Usage: ./exercise3 count STRING\n");
            return 1;
        }

        int vowels = 0, consonants = 0;

        for (int i = 0; argv[2][i] != '\0'; i++)
        {
            char ch = tolower((unsigned char)argv[2][i]);

            if (ch >= 'a' && ch <= 'z')
            {
                if (ch == 'a' || ch == 'e' ||
                    ch == 'i' || ch == 'o' || ch == 'u')
                    vowels++;
                else
                    consonants++;
            }
        }

        printf("Vowels: %d\n", vowels);
        printf("Consonants: %d\n", consonants);
    }
    else if (strcmp(argv[1], "add") == 0 ||
             strcmp(argv[1], "multiply") == 0)
    {
        if (argc != 4)
        {
            printf("Usage: ./exercise3 add NUM1 NUM2\n");
            return 1;
        }

        int a = atoi(argv[2]);
        int b = atoi(argv[3]);

        if (strcmp(argv[1], "add") == 0)
            printf("Addition: %d\n", a + b);
        else
            printf("Multiplication: %d\n", a * b);
    }
    else
    {
        printf("Invalid operation!\n");
        return 1;
    }

    return 0;
}
