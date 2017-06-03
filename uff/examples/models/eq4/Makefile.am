bin_PROGRAMS    = main
main_SOURCES    = main.c pythagoras.c eq2.c eq3.c eq4.c array.c
main_CFLAGS     = -O0 -Wall -ansi -Werror -DDOUBLE_PRECISION -DDECNUMBER -DBOOLTYPE
# -DDOUBLE_PRECISION
# -DDECNUMBER
# -DBOOLTYPE
main_LDADD      = -lm
#include_HEADERS = datatype.h real.h eq2.h eq3.h complex.h array.h

##############################################################################
# -- VALGRIND -------------------------------------------------------------- #
##############################################################################
mem: $(bin_PROGRAMS)
	valgrind --leak-check=full -v  ./$(bin_PROGRAMS) 1 -10 35 -50 24
##############################################################################
# -- GDB ------------------------------------------------------------------- #
##############################################################################
test-1: $(bin_PROGRAMS)
	gdb --batch --command=$@.gdb --args ./$(bin_PROGRAMS)
test-2: $(bin_PROGRAMS)
	gdb --batch --command=$@.gdb --args ./$(bin_PROGRAMS)
