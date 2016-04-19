#include <stdio.h>
#include <stdlib.h>

#include "audio.h"

#define VERSION "0.1.1"

int main (int argc, char *argv[])
{
	PaInitialization();
	PaOpenStream();
	return EXIT_SUCCESS;
}
