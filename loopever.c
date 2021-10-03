#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "loopever.h"

int main(int argc, char **argv)
{
	long sleepsec = parseArg(argc, argv);
	while (1)
	{
		sleep(sleepsec);
	}
	return 0;
}

unsigned long parseArg(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Specify sleepsec\n");
		exit(1);
	}

	char *endPtr = NULL;
	errno = 0;
	unsigned long sleepsec = strtoul(*(argv + 1), &endPtr, 10);
	if (*endPtr != '\0' || errno != 0)
	{
		fprintf(stderr, "Failed to stroul sleepsec.\n");
		exit(1);
	}
	return sleepsec;
}
