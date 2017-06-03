bin_PROGRAMS  = main
main_SOURCES  = ex-1.c
main_CPPFLAGS = -Wall -ansi -Werror

mem: $(bin_PROGRAMS)
	valgrind --leak-check=full -v  ./$(bin_PROGRAMS)

gdb: $(bin_PROGRAMS)
	gdb --batch --command=$(bin_PROGRAMS).gdb --args ./$(bin_PROGRAMS) 5
