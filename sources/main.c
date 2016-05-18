/**
 * @file		main.c
 * @brief		Main file to run the program Ears Wide Open
 */
#include <stdio.h>
#include <stdlib.h>

#include "audio.h"

int main(int argc, char *argv[])
{
	PaOpenStream();
	return EXIT_SUCCESS;
}
