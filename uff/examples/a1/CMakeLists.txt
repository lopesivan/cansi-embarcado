cmake_minimum_required(VERSION 3.2.2)
project(uff)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -ansi -Werror -D_BSD_SOURCE")

# Bring the headers into the project
include_directories(include)

# libm
link_libraries(m)

#Can manually add the sources using the set command as follows:
set(HEADERS
  array.h
  bitree.h
  chtbl.h
  complex.h
  datatype.h
  eq2.h
  eq3.h
  eq4.h
  except.h
  lex.h
  list.h
  narray.h
  pythagoras.h
  real.h
  stack.h
  symbol.h
  traverse.h
  util.h
)

#Can manually add the sources using the set command as follows:
set(SOURCES
  exemplo13.c
)

#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB SOURCES "source/*.c")

add_executable(main ${SOURCES} ${HEADERS})

