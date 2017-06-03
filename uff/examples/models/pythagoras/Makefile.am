bin_PROGRAMS    = main
main_SOURCES    = main.c pythagoras.c
main_CFLAGS     = -Wall -ansi -Werror
main_LDADD      = -lm
include_HEADERS = datatype.h real.h pythagoras.h

gdb: $(bin_PROGRAMS)
	gdb --batch --command=$(bin_PROGRAMS).gdb --args ./$(bin_PROGRAMS)
