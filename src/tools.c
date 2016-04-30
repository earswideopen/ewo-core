#include <stdio.h>

unsigned int ModuloInc(const unsigned int value, const unsigned int modulus) {
	unsigned int my_value = value + 1;

	if(my_value >= modulus)
		my_value = 0;

	return my_value;
}
