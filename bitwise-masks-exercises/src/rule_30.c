#include "rule_30.h"
#include "evolution.h"

#include <stdio.h>
#include <limits.h>

void print_bin(uint64_t);

void rule_30(uint64_t initial_state, int steps_count) {
	print_bin(initial_state);
	uint64_t current_state = evolution(initial_state);
	for (int i = 0; i < steps_count; i++) {
		current_state = evolution(current_state);
		print_bin(current_state);
	}
}

void print_bin(uint64_t number) {
	uint64_t mask = ULONG_MAX;
	printf("\n");
	while (mask > 0) {
		if ((number & mask) == 0) {
			printf("0");
		} else printf("1");
		mask >>= 1;
	}
	fflush(stdout);
}
