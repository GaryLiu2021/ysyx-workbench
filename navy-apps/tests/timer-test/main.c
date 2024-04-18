#include <sys/time.h>
#include <time.h>
#include <stdio.h>

int main() {
	struct timeval tv;
	// struct timezone tz;
	gettimeofday(&tv, NULL);
	__uint64_t ms = 500;
	printf("ms = %d\n", ms);
	while (1) {
		while ((tv.tv_sec * 1000 + tv.tv_usec / 1000) < ms) {
			gettimeofday(&tv, NULL);
		}
		printf("ms = %d\n", ms);
		ms += 500;
		printf("ms = %d\n", ms);
	}
}