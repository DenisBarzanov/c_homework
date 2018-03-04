#include "../src/check_mask.h"
#include "../src/count_ones.h"
#include "../src/is_power_of_2.h"
#include "../src/restore_data.h"
#include "../src/new_released.h"
#include "../src/new_pressed.h"
#include "../src/evolution.h"
#include "../src/rule_30.h"

#include <stdlib.h>
#include <stdio.h>

#define RED "\033[0;32m" // bash color red
#define NO_COLOR "\033[0m" // bash no color



#test check_mask_works_properly

	uint32_t mask = 	0b1;
	uint32_t number = 	0b1;
	ck_assert_msg(check_mask(mask, number));
	
	mask = 			0b0011010;
	number = 		0b1011010;
	ck_assert_msg(check_mask(mask, number));

#test check_counts_ones_correctly
	
	uint32_t number = 	0b10011110;
	uint32_t expected = 	5;
	ck_assert(count_ones(number) == expected);

#test check_is_power_of_2_is_correct
	uint32_t number = 	0b10000000;
	ck_assert_msg(is_power_of_2(number), 
	"1 -- \nNumber seems not to be a power of 2!!!");

	number = 		0b0;
	ck_assert_msg(!is_power_of_2(number), "2 --");
	
	number = 		0b10010011011;
	ck_assert_msg(!is_power_of_2(number), "3 --");

#test check_new_pressed_keys_are_pressed_correctly
	uint32_t old_state = 	0b10010001;
	uint32_t new_state =	0b10100110;
	uint32_t expected = 	0b00100110;
	
	ck_assert(new_pressed(old_state, new_state) == expected);

#test check_new_released_keys_are_really_released
	uint32_t old_state = 	0b10011001;
	uint32_t new_state =	0b10110110;
	uint32_t expected = 	0b00001001;
	
	ck_assert(new_released(old_state, new_state) == expected);


#test check_restores_data_correctly
	uint32_t data1 = 	0b100111010;
	uint32_t xor = 		0b100110100;
	uint32_t expected =	0b000001110;
	
	ck_assert_msg(restore_data(data1, xor) == expected, "1 -- Doesn't restore data correctly");
	data1 = 		0b100100010;
	xor =			0b101010010;
	expected =		0b001110000;
	
	ck_assert_msg(restore_data(data1, xor) == expected, "2 -- ");

#test check_evolution_tools_work_correctly
	uint8_t bits = 		0b101;
	uint8_t expected_evolved_bit = 
				0b0;
	
	ck_assert(get_evolved_bit(bits) == expected_evolved_bit);

	
	bits = 			0b011;
	expected_evolved_bit = 	0b1;
	
	ck_assert(get_evolved_bit(bits) == expected_evolved_bit);

	
	
	uint64_t state = 	0b000000001110000000;
	uint8_t bit = 		0b1;
	set_evolved_bit_to_new_state(&state, bit, 4);
	uint64_t expected_state =
				0b000000001110010000;
	
	char* message = malloc(sizeof(char) * 50);

	sprintf(message, "\nState: %ld, bit: %d, expected_state: %ld",
			state, bit, expected_state);

	ck_assert_msg(state == expected_state, message);

	free(message);
	
#test check_evolution_works_correctly

	uint64_t state = 	0b000000001110000000;
	uint64_t expected = 	0b000000011001000000;
	
	char* message = malloc(sizeof(char) * 50);
	uint64_t result_state = evolution(state);
	sprintf(message, "\nFor %ld: \n"
		"%ld was expected, but got %ld", state, expected, result_state);
	ck_assert_msg(result_state == expected, message);

	free(message);

#test check_rule_30_prints_correctly
	//uint64_t initial_state = 0b000000001110000000;
	//rule_30(initial_state, 8);
	ck_assert_msg(false, "\nIn Rule 30:"
		"\nCannot catch errors, due to printf in fd - 1");
