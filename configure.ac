AC_INIT([earswideopen], [0.1.0-alpha.2], [matthieu@berjon.net])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_SEARCH_LIBS([snd_pcm_open], [asound], [], AC_MSG_ERROR(ALSA support requires the asound library!))
AC_SEARCH_LIBS([cos], [m], [], AC_MSG_ERROR(Portaudio requires the M library))
AC_SEARCH_LIBS([pthread_create], [pthread], [], AC_MSG_ERROR(RtAudio requires the pthread library!))
AC_SEARCH_LIBS([Pa_GetVersion], [portaudio], [], AC_MSG_ERROR(Portaudio is required))
AC_PROG_CC
AC_CONFIG_FILES([Makefile src/Makefile tools/Makefile])
AC_OUTPUT
