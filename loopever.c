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
		loopWithSleep(argc, argv);
	}
	return 0;
}

void loop()
{
	while (1)
	{
	}
}

void loopWithSleep(int argc, char **argv)
{
	struct timespec sleeptime;
	parseArg(argc, argv, &sleeptime);

	while (1)
	{
		nanosleep(&sleeptime, NULL);
	}
}

void parseArg(int argc, char **argv, struct timespec *result)
{

	char *endPtr = NULL;
	errno = 0;
	const int sleepsec = strtol(*(argv + 1), &endPtr, 10);
	if (*endPtr != '\0' || errno != 0)
	{
		fprintf(stderr, "Failed to strtol sleepsec.\n");
		exit(1);
	}
	result->tv_sec = sleepsec;

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
