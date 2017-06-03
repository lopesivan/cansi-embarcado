CC = gcc
LD = $(CC)

CFLAGS   = -c -Wall -Werror -ansi
LDFLAGS  = -o
GDBFLAGS = -g
LIBS     =

sources := main.c StartedState.c StoppedState.c TableBased.c WatchState.c
target  := main
targets := $(target)

# Compile
.c.o:
	$(CC) $(GDBFLAGS) $(CFLAGS) $<

all: $(targets)

main: main.o WatchState.o
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)

clean:
	/bin/rm -rf $(target) $(sources:.c=.o)
# END OF FILE
