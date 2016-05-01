/**
 * @file		tools.c
 * @brief		Small function tools used here and there
 */
#include <stdio.h>

/**
 * @fn		unsigned int ModuloInc(const unsigned int value, const unsigned int modulus)
 * @brief	Modulo computation for buffer size.
 *
 * @param[in]	value		input value of the buffer
 * @param[in]	modulus		value of the modulus used
 *
 * @return	return the value of the modulus
 */
unsigned int ModuloInc(const unsigned int value, const unsigned int modulus)
{
	unsigned int my_value = value + 1;

	if (my_value >= modulus)
		my_value = 0;

	return my_value;
}
