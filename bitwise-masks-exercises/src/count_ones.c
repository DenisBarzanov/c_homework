#include "count_ones.h"

int count_ones(int number) {
	int result = 0;
	for (int i = 0; i < sizeof(number) * 8 - 1; i++) {
		int mask = 1 << i;
		if (number & mask) {
			result++;
		}
	}
	return result;
}
