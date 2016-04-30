#include <stdio.h>
#include <stdlib.h>
#include "portaudio.h"

void DevicesInfo(void)
{
	const PaDeviceInfo *devices_info;
	int i, devices_nb;
	PaError error;

	error = Pa_Initialize();
	if (error != paNoError) {
		fprintf(stderr, "Error: %s\n", Pa_GetErrorText(error));
		exit(EXIT_FAILURE);
	}

	devices_nb = Pa_GetDeviceCount();
	if (devices_nb < 0) {
		fprintf(stderr, "Error: no device found\n");
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "Devices information\n");
	fprintf(stdout, "-------------------\n");
	for (i = 0; i < devices_nb; i++) {
		devices_info = Pa_GetDeviceInfo(i);
		fprintf(stdout,
			"#%i: %s\n",
			i,
			devices_info->name);
		fprintf(stdout,
			"\tin: %d\n",
			devices_info->maxInputChannels);
		fprintf(stdout,
			"\tout: %d\n",
			devices_info->maxOutputChannels);
		fprintf(stdout,
			"\tsamplerate: %f\n",
			devices_info->defaultSampleRate);
	}
}

int main(int argc, char *argv[])
{
	DevicesInfo();
	return EXIT_SUCCESS;
}
