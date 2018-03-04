#include <stdbool.h>
#include "check_mask.h"
#include <stdint.h>

bool check_mask(uint32_t mask, uint32_t number) {
	/*
	 * Checks if all bits from the @mask are up in @number
	 */
	return (number & mask) == mask;
}
