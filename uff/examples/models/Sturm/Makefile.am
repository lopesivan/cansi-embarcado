bin_PROGRAMS    = main
main_SOURCES    = main.c sturm.c util.c
main_CFLAGS     = -O0 -Wall -ansi -DDOUBLE_PRECISION
main_LDADD      = -lm
include_HEADERS = solve.h

mem: $(bin_PROGRAMS)
	valgrind --leak-check=full -v  ./$(bin_PROGRAMS)

test-1: $(bin_PROGRAMS)
	gdb --batch --command=$@.gdb --args ./$(bin_PROGRAMS)
test-2: $(bin_PROGRAMS)
	gdb --batch --command=$@.gdb --args ./$(bin_PROGRAMS)
