#ifndef EVOLUTION_H
#define EVOLUTION_H

#include <stdint.h>

uint64_t evolution(uint64_t);
uint8_t get_evolved_bit(uint8_t);
void set_evolved_bit_to_new_state(uint64_t* new_state, uint8_t bit, uint8_t index);

#endif
