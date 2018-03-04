#include "evolution.h"
#include <stdio.h>


uint64_t evolution(uint64_t state) {
	uint64_t new_state = 0;
	for (int i = 0; i < sizeof(uint32_t) * 8 - 2; i++) { /* -2 for excluding 
							the last 2 iterations */
		uint64_t current_indexed_bits = 0b111 << i;
		uint64_t current_state_block = state & current_indexed_bits;
		uint8_t evolved_bit = get_evolved_bit(current_state_block >> i);
		set_evolved_bit_to_new_state(&new_state, evolved_bit, i + 1);
	}
	return new_state;
}


uint8_t get_evolved_bit(uint8_t bits_3) {
	uint8_t result_bit;
	switch (bits_3) {
		case 0b100:
		case 0b011:
		case 0b010:
		case 0b001:
			result_bit = 1;
			break;
		default:
			result_bit = 0;
	}
	return result_bit;
}


void set_evolved_bit_to_new_state(uint64_t* new_state, uint8_t bit, uint8_t index) {
	*new_state = (*new_state & (~(1 << index))) | (bit << index);
}
