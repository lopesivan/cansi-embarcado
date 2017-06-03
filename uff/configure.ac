#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_INIT([hello], [0.02], [ivan@42algoritmos.com.br],
        [hello], [http://42algoritmos.com.br/])
# Force autoconf to be at least this version number:
AC_PREREQ([2.68])
# Safety check - list a source file that wouldn't be in other directories:
AC_CONFIG_SRCDIR([about.c])
# Put configuration results here, so we can easily #include them:
AC_CONFIG_HEADERS([config.h])
# Put autotools auxiliary files in a subdir, so they don't clutter top dir:
AC_CONFIG_AUX_DIR([build-aux])
# The modern autotools convention is that you should use an “m4” subdirectory
# for internal “m4” files, instead of the default aclocal.m4.
AC_CONFIG_MACRO_DIR([m4])
# Enable "automake" to simplify creating makefiles:
AM_INIT_AUTOMAKE([1.11 -Wall -Werror])

# Checks for programs.
AC_PROG_CC
AM_PROG_AR
AM_PROG_CC_C_O

# We use libraries
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([source/Makefile])
AC_CONFIG_FILES([examples/list/Makefile])
AC_CONFIG_FILES([examples/tree/Makefile])
AC_CONFIG_FILES([examples/dynarrays/Makefile])
AC_CONFIG_FILES([examples/gdb/01/Makefile])
AC_CONFIG_FILES([examples/models/pythagoras/Makefile])
AC_CONFIG_FILES([examples/models/eq2/Makefile])
AC_CONFIG_FILES([examples/models/eq3/Makefile])
AC_CONFIG_FILES([examples/models/eq4/Makefile])
AC_CONFIG_FILES([examples/models/tree/Makefile])
AC_CONFIG_FILES([examples/models/Sturm/Makefile])

AC_OUTPUT

AC_MSG_RESULT(
[
--------------------------------------------------
 ${PACKAGE_NAME} Version ${PACKAGE_VERSION}

 Prefix: '${prefix}'.
 Compiler: '${CC} ${CFLAGS}'
 Libraries: '${LIBS}'

 Package features:
   Async Execution: ${async_exec}

 Now type 'make @<:@<target>@:>@'
   where the optional <target> is:
     all                - build all binaries
     install            - install everything

--------------------------------------------------])
