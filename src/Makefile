#
# Tools Makefile
#
# To enable DEBUG mode, use the command
# > make DEBUG=True
#

TARGET = ewo
SRC_DIR = .
SRC_EXT = c
BUILD_DIR = build
OBJ_DIR = obj
ARCH = $(shell uname -m)

CC ?= gcc
CFLAGS += -std=c11 -Wall -Werror -pedantic-errors

ifndef DEBUG
	ADDITIONAL_CXXFLAGS ?= -O2
else
	ADDITIONAL_CXXFLAGS ?= -g -v
endif


CFLAGS += ${ADDITIONAL_CXXFLAGS}

LIBS += jack portaudio-2.0
LDLIBS = $(shell pkg-config --libs $(LIBS))
LDLIBS += 
#LDLIBS += -lboost_program_options
SOURCES := $(shell find $(SRC_DIR) -name '*.$(SRC_EXT)')
OBJECTS = $(SOURCES:.$(SRC_EXT)=.o)

RM ?= rm -rf

#default: all


# EXEC without rules
.PHONY: clean, mrproper

# Deactivation of implicit rules
.SUFFIXES:

all: $(TARGET)

$(TARGET): main.c tools.c audio.c ringbuffer.c
	@echo "Building $@..."
	@echo $(ARCH)
	@echo $(SOURCES)
	@echo $(OBJECTS)
	$(CC) $^ -o $(TARGET) $(CFLAGS) $(LDLIBS)




#ewo: main.o
#	$(CC) -o $@ $^ $(LDLIBS)

#%.o: %.c
#	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	$(RM) $(TARGET)

mrproper:
	$(RM) $(EXEC)
