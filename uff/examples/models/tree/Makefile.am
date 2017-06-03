bin_PROGRAMS    = main
main_SOURCES    = main.c            \
                  pythagoras.c      \
                  eq2.c eq3.c eq4.c \
                  narray.c array.c

main_CFLAGS     = -O0 -ggdb3 -Wall -ansi -Werror \
                  -I$(top_srcdir)/include        \
                  -DDOUBLE_PRECISION -DDECNUMBER -DBOOLTYPE
# -DDOUBLE_PRECISION
# -DDECNUMBER
# -DBOOLTYPE
main_LDADD      = -lm $(top_srcdir)/source/libbitree.a

##############################################################################
# -- VALGRIND -------------------------------------------------------------- #
##############################################################################
mem: $(bin_PROGRAMS)
	valgrind --leak-check=full -v ./$(bin_PROGRAMS)
##############################################################################
# -- GDB ------------------------------------------------------------------- #
##############################################################################
t : $(bin_PROGRAMS)
	gdb --batch --command=test.gdb --args ./$(bin_PROGRAMS)
it: $(bin_PROGRAMS)
	gdb --command=test.gdb --args ./$(bin_PROGRAMS)
