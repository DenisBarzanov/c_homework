#include "new_pressed.h"

int new_pressed(uint32_t old_state, uint32_t new_state) {
	return (~old_state) & new_state;
}
