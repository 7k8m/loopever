#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{

	if (argc < 2)
	{
		fprintf(stderr, "Specify sleepsec\n");
		return 1;
	}

	char *endPtr = NULL;
	errno = 0;
	long sleepsec = strtol(*(argv + 1), &endPtr, 10);
	if (*endPtr != '\0' || errno != 0)
	{
		fprintf(stderr, "Failed to strol sleepsec.\n");
		return 1;
	}

	while (1)
	{
		sleep(sleepsec);
	}
	return 0;
}
