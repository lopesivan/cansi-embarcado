bin_PROGRAMS    = main
main_SOURCES    = main.c eq2.c array.c
main_CFLAGS     = -Wall -ansi -Werror
main_LDADD      = -lm
include_HEADERS = datatype.h real.h eq2.h complex.h array.h

mem: $(bin_PROGRAMS)
	valgrind --leak-check=full -v  ./$(bin_PROGRAMS) 12 3 4

test-1: $(bin_PROGRAMS)
	gdb --batch --command=$@.gdb --args ./$(bin_PROGRAMS)
test-2: $(bin_PROGRAMS)
	gdb --batch --command=$@.gdb --args ./$(bin_PROGRAMS)
