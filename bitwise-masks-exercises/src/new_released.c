#include "new_released.h"

uint32_t new_released(uint32_t old_state, uint32_t new_state) {
	return old_state & (~new_state);
}
