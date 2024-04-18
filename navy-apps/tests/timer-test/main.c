#include <sys/time.h>
#include <time.h>
#include <stdio.h>

int main() {
	struct timeval tv;
	// struct timezone tz;
	gettimeofday(&tv, NULL);
	__uint32_t ms = 500;
	while (1) {
		while ((tv.tv_sec * 1000 + tv.tv_usec / 1000) < ms) {
			gettimeofday(&tv, NULL);
		}
		ms += 500;
		printf("ms = %d\n", ms);
	}
}