#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	// set and check if saved
	if (!putenv("TEXT=hello"))
		puts(getenv("TEXT"));

	// unset and check if saved
	if (!unsetenv("TEXT"))
	{
		if (getenv("TEXT") != NULL)
			puts(getenv("TEXT"));
		else
			puts("Not found");
	}                                                                 
	return EXIT_SUCCESS;
}
