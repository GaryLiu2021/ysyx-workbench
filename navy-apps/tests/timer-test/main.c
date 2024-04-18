#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <NDL.h>

int main() {
	uint32_t curTick = 0;
	NDL_Init(0);
	uint32_t ms = 500;
	curTick = NDL_GetTicks();
	while (1) {
		while (curTick < ms) {
			curTick = NDL_GetTicks();
		}
		ms += 500;
		printf("ms = %d\n", ms);
	}
	NDL_Quit();
}