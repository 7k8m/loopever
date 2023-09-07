#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "loopever.h"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		loop();
	}
	else
	{
		struct timespec sleeptime;
		parseArg(argc, argv, &sleeptime);
		loopWithSleep(&sleeptime);
	}
	return 0;
}

void loop()
{
	while (1)
	{
	}
}

void loopWithSleep(struct timespec *sleepTime)
{
	while (1)
	{
		nanosleep(sleepTime, NULL);
	}
}

void parseArg(int argc, char **argv, struct timespec *result)
{
	// check number of argument
	if (argc < 2 || argc > 3)
	{
		fprintf(stderr, "Error: not enough arguments\n");
		exit(1);
	}

	// convert first argument to integer
	char *endPtr = NULL;
	errno = 0;
	const int sleepsec = strtol(*(argv + 1), &endPtr, 10);
	if (*endPtr != '\0' || errno != 0)
	{
		fprintf(stderr, "Failed to strtol sleepsec.\n");
		exit(1);
	}
	result->tv_sec = sleepsec;

	// convert second argument to integer
	if (argc > 2)
	{
		const long sleepnsec = strtol(*(argv + 2), &endPtr, 10);
		if (*endPtr != '\0' ||
			errno != 0 ||
			sleepnsec < MIN_SLEEP_NANO_SEC ||
			sleepnsec > MAX_SLEEP_NANO_SEC)
		{
			fprintf(stderr, "Failed to strtol sleepnsec in the range\n");
			exit(1);
		}
		result->tv_nsec = sleepnsec;
	}
	else
	{
		result->tv_nsec = 0;
	}
}
