#ifndef _audio_h
#define _audio_h
#include "portaudio.h"

void PaInitialization(void);
void PaOpenStream(void);
int PlayrecCallback(const void *input_buffer,
			   void *output_buffer,
			   unsigned long frames_per_buffer,
			   const PaStreamCallbackTimeInfo *time_info,
			   PaStreamCallbackFlags status_flags,
			   void *user_data);

#endif /* _audio_h */
