#SUBDIRS = src tools test


bin_PROGRAMS = ewo devinfo
ewo_SOURCES = \
			  src/main.c \
			  src/audio.c \
			  src/tools.c \
			  src/ringbuffer.c \
			  src/filters.c \
			  src/parser.c

devinfo_SOURCES = tools/devices_info.c

check_PROGRAMS = test/test_tools
TESTS = test/test_tools
test_test_tools_SOURCES = test/test_tools.c src/tools.c
#test_tools_CFLAGS = -Isrc/
#test_tools_LDFLAGS = -lcmocka
