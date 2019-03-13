#******************************************************************************
# Copyright (C) 2019 by Joseph George
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Joseph George is not liable for any misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile that compiles multiple source files and supports two platform targets
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = 

# Define flags for: Generalized, MSP432, and HOST
GEN_CFLAGS = -Wall \
			-Werror \
			-g \
			-O0 \
			-std=c99
ARM_CFLAGS = -mcpu=cortex-m4 \
			-mthumb \
			-march=armv7e-m \
			-mfloat-abi=hard \
			-mfpu=fpv4-sp-d16 \
			--specs=nosys.specs
L_FILE = ../msp432p401r.lds
ARM_TARGET = -DMSP432
HOST_TARGET = -DHOST

# Map file name
MAP_FILE = c1m2

ifeq ($(PLATFORM),HOST)
	CC = gcc
	CPPFLAGS = $(HOST_TARGET)
	LDFLAGS = -Wl,-Map=$(MAP_FILE).map $(INCLUDES)
	CFLAGS = $(GEN_CFLAGS)
else ifeq ($(PLATFORM),MSP432)
	LINKER_FILE = $(L_FILE)
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs

	CC = arm-none-eabi-gcc
	CPPFLAGS = $(ARM_TARGET)
	LDFLAGS = -Wl,-Map=$(MAP_FILE).map $(INCLUDES) -T $(L_FILE)
	CFLAGS = $(GEN_CFLAGS) $(ARM_CFLAGS)
endif

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c $< -o $@

%.i : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -E $< -o $@

%.asm : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c $< -o $@
	objdump -S $@

OBJS:=$(SOURCES:.c=.o)

.PHONY: build
build: c1m2.out
c1m2.out: $(SOURCES)
		$(CC) $(SOURCES) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o c1m2.out
		size c1m2.out

# compiles without linking
.PHONY: compile-all
compile-all: $(SOURCES)
		$(CC) $(SOURCES) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c $^

.PHONY: clean
clean:
		rm -f *.o *.asm *.i *.d *.map *.out