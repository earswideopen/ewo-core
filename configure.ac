# Autoconf requirements
AC_INIT([earswideopen], [0.1.0-alpha.2], [matthieu+ewo-bugs@berjon.net])
AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects])

# Information about the package

AC_CANONICAL_HOST

# Check for programs

AC_PROG_CC([gcc])
PKG_CHECK_MODULES([CMOCKA], [cmocka])

# Check for libraries

AC_SEARCH_LIBS(\
               [snd_pcm_open], \
               [asound], \
               [], \
               AC_MSG_ERROR(ALSA support requires the asound library!)\
               )
AC_SEARCH_LIBS(\
               [cos], \
               [m], \
               [], \
               AC_MSG_ERROR(Portaudio requires the M library)\
               )
AC_SEARCH_LIBS(\
               [pthread_create], \
               [pthread], \
               [], \
               AC_MSG_ERROR(RtAudio requires the pthread library!)\
               )
AC_SEARCH_LIBS(\
               [Pa_GetVersion], \
               [portaudio], \
               [], AC_MSG_ERROR(Portaudio is required)\
               )


# Check for header files

AC_CHECK_HEADERS([stdlib.h stdio.h])

# Check for types
# Check for structures


# Check for compiler characteristics



# Check for library functions
# Check for system services


AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_FILES([\
                 Makefile \
                 src/Makefile \
                 tools/Makefile \
                 test/Makefile
                 ])
AC_OUTPUT
