#include <stdio.h> #include <stdlib.h> #include <unistd.h> char globBuf[65536];         /* Uninitialized data segment */ int primes[] = {2, 3, 5, 7}; /* Initialized data segment */ static int square(int x) /* Allocated in frame for square() */ { int result; /* Allocated in frame for square() */ result = x * x; return result; /* Return value passed via register */ } static void doCalc(int val) /* Allocated in frame for doCalc() */ { printf("The square of %d is %d\n", val, square(val)); if (val < 1000) { } } int t; /* Allocated in frame for doCalc() */ t = val * val * val; printf("The cube of %d is %d\n", val, t); int main(int argc, char *argv[]) /* Allocated in frame for main() */{ static int key = 9973;      /* Initialized data segment */ static char mbuf[10240000]; /* Uninitialized data segment */ char *p;                    /* Allocated in frame for main() */ p = malloc(1024);           /* Points to memory in heap segment */ printf("\nMemory addresses of variables and segments:\n"); printf("---------------------------------------------------\n"); printf("Address of function main() (Text): %p\n", (void *)main); printf("Address of function doCalc() (Text): %p\n", (void *)doCalc); printf("Address of globBuf (BSS): %p\n", (void *)globBuf); printf("Address of primes (Initialized Data): %p\n", (void *)primes); printf("Address of key (Initialized Data): %p\n", (void *)&key); printf("Address of mbuf (BSS): %p\n", (void *)mbuf); printf("Address of malloc'd memory (Heap): %p\n", (void *)p); printf("Address of local variable p (Stack): %p\n", (void *)&p); printf("\nTo see segment boundaries, check /proc/%d/maps\n", getpid()); doCalc(key); printf("\nPress Enter to continue...\n"); getchar(); // Wait for user input to proceed free(p); return EXIT_SUCCESS; }#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char globBuf[65536];

int primes[] = {2, 3, 5, 7};

static int square(int x)
{
    int result;

    result = x * x;

    return result;
}

static void doCalc(int val)
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000)
    {
        int t;

        t = val * val * val;

        printf("The cube of %d is %d\n", val, t);
    }
}

int main(int argc, char *argv[])
{
    static int key = 9973;
    static char mbuf[10240000];

    char *p;

    p = malloc(1024);

    printf("\nMemory addresses of variables and segments:\n");
    printf("----------------------------------------------------\n");

    printf("Address of function main() (Text): %p\n",
           (void *)main);

    printf("Address of function doCalc() (Text): %p\n",
           (void *)doCalc);

    printf("Address of globBuf (BSS): %p\n",
           (void *)globBuf);

    printf("Address of primes (Initialized Data): %p\n",
           (void *)primes);

    printf("Address of key (Initialized Data): %p\n",
           (void *)&key);

    printf("Address of mbuf (BSS): %p\n",
           (void *)mbuf);

    printf("Address of malloc'd memory (Heap): %p\n",
           (void *)p);

    printf("Address of local variable p (Stack): %p\n",
           (void *)&p);

    printf("\nTo see segment boundaries, check /proc/%d/maps\n",
           getpid());

    doCalc(key);

    printf("\nPress Enter to continue...\n");

    getchar();

    free(p);

    return EXIT_SUCCESS;
}#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char globBuf[65536];
int primes[] = {2,3,5,7};

static int square (int x){
int result;
result = x*x;
return result;
}

static void doCalc(int val){
	printf("The square of %d is %d\n",val,square(val));
	if(val<1000)
	{
		int t;
		t=val*val*val;
		printf("The cube is %d is %d\n",val,t);
	}
}

int main(int argc,char *argv[]){
	static int key = 9973;
	static char mubf[10240000];
	char *p;
	p = malloc(1024);

	printf("\nMemory addesses of variables and segments:\n");
	printf("----------------------------------------------------\n");
	printf("Address of function main() (Text): %p\n",(void *)main);
	printf("Address of function docalc() (Text): %p\n",(void *)doCalc);
	printf("Address of globBuf (BSS): %p\n", (void *)globBuf);
	printf("Address of primes (Inatialized Data) : %p\n", (void*)primes); 
	printf("Address of key (Initialized Data): %p\n", (void *)&key);
	printf("Address of mbuf (BSS) %p\n",(void *)mbuf);
	printf("Address of malloc'd memory (Heap): %p\n",(void *)p);
	printf("Address of local variable p (Stack): %p\n", (void *)&p);
	
	printf("\nTo see segment boundaries, check /proc/%d/maps\n",getpid());

	doCalc(key);
	
	printf("\nPress Enter to continue...\n");
	getchar();
	
	free(p);
	return EXIT_SUCCESS;
}
