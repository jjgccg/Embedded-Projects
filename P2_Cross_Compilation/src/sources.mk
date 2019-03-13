#******************************************************************************
# Copyright (C) 2019 by Joseph George
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Joseph George is not liable for any misuse of this material. 
#
#*****************************************************************************

SOURCES = main.c \
			memory.c

INCLUDES = -I../include/msp432/ \
		-I../include/common/ \
		-I../include/CMSIS