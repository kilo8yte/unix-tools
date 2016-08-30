CC= gcc
CFLAGS= -Wall -std=c99
LIBS=
FILES=$(shell echo *.c)
OUTFILES=$(FILES:%.c=%)

all:
	@for sourcefile in $(OUTFILES); \
	do \
		$(CC) $(CFLAGS) $${sourcefile}.c -o ./bin/$${sourcefile}; \
	done

install:
