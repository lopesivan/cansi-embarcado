bin_PROGRAMS  = main
main_SOURCES  = ex-1.c

main_CFLAGS   = -O0 -ggdb3 -Wall -ansi -Werror -I$(top_srcdir)/include
main_LDADD    = $(top_srcdir)/source/libbitree.a \
                $(top_srcdir)/source/liblist.a   \
                $(top_srcdir)/source/libtraverse.a
##############################################################################
# -- VALGRIND -------------------------------------------------------------- #
##############################################################################
mem: $(bin_PROGRAMS)
	valgrind --leak-check=full -v  ./$(bin_PROGRAMS) 1 -10 35 -50 24
##############################################################################
# -- GDB ------------------------------------------------------------------- #
##############################################################################
test: $(bin_PROGRAMS)
	gdb --batch --command=$@.gdb --args ./$(bin_PROGRAMS)
itest: $(bin_PROGRAMS)
	gdb --command=test.gdb --args ./$(bin_PROGRAMS)
