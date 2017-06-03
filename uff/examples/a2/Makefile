CC = gcc
LD = $(CC)

CFLAGS   = -c -Wall -Werror -ansi -DDOUBLE_PRECISION
LDFLAGS  = -o
GDBFLAGS = -g
LIBS     =

sources := main.c matrix.c narray.c
target  := main
targets := $(target)

# Compile
.c.o:
	$(CC) $(GDBFLAGS) $(CFLAGS) $<

all: $(targets)

main: main.o matrix.o narray.o
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)

memory: main
	valgrind --leak-check=full -v ./$^

clean:
	/bin/rm -rf $(target) $(sources:.c=.o)
# END OF FILE
