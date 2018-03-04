#include "is_power_of_2.h"

bool is_power_of_2(uint32_t number) {
	return (!((number - 1) & number)) && number;
	/* && number because if number == 0, 
	   then it is not power of 2 */
}
