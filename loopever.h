#include <time.h>
const long MIN_SLEEP_NANO_SEC = 0;
const long MAX_SLEEP_NANO_SEC = 999999999;

void loop();
void loopWithSleep(struct timespec *sleepTime);

void parseArg(int argc, char **argv, struct timespec *result);