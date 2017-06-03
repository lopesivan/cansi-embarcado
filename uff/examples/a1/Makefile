CC = gcc
LD = $(CC)

CFLAGS   = -c -Wall -Werror -ansi -D_BSD_SOURCE
LDFLAGS  = -o
GDBFLAGS = -g
LIBS     = -lm

# objs
exemplo1_objs = ex-1.o array.o bitree.o eq2.o eq3.o eq4.o list.o main.o narray.o pythagoras.o stack.o traverse.o
exemplo2_objs = exemplo2.o chtbl.o lex.o symbol.o
exemplo3_objs = exemplo3.o
exemplo4_objs = exemplo4.o
exemplo5_objs = exemplo5.o
exemplo6_objs = exemplo6.o list.o stack.o
exemplo7_objs = exemplo7.o list.o stack.o
exemplo8_objs = exemplo8.o
exemplo9_objs = exemplo9.o
exemplo10_objs = exemplo10.o
exemplo11_objs = exemplo11.o
exemplo12_objs = exemplo12.o
exemplo13_objs = exemplo13.o
exemplo14_objs = exemplo14.o
exemplo15_objs = exemplo15.o

sources := $(wildcard *.c)
targets := \
	exemplo1 \
	exemplo2

# Compile
.c.o:
	$(CC) $(GDBFLAGS) $(CFLAGS) $<

all: $(targets)

string: string.o
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)

exemplo1: $(exemplo1_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo2: $(exemplo2_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo3: $(exemplo3_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo4: $(exemplo4_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo5: $(exemplo5_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo6: $(exemplo6_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo7: $(exemplo7_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo8: $(exemplo8_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo9: $(exemplo9_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo10: $(exemplo10_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo11: $(exemplo11_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo12: $(exemplo12_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo13: $(exemplo13_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo14: $(exemplo14_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
exemplo15: $(exemplo15_objs)
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)
equation: equation.o
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)

infix_postfix_using_stack: infix_postfix_using_stack.o
	$(CC) $(LDFLAGS) $@ $^ $(LIBS)

clean:
	/bin/rm -rf $(target) $(sources:.c=) $(sources:.c=.o)
# END OF FILE
