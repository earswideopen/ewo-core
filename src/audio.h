#include "portaudio.h"

void PaInitialization();
void PaOpenStream();
int PlayrecCallback(const void *input_buffer,
			   void *output_buffer,
			   unsigned long frames_per_buffer,
			   const PaStreamCallbackTimeInfo* time_info,
			   PaStreamCallbackFlags status_flags,
			   void *user_data);
