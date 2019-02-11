CFLAGS=-Wall -std=c11
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

lg: $(OBJS)
	gcc -o lg $(OBJS) $(LDFLAGS) -lncursesw

$(OBJS): lg.h

clean:
	rm -f tocc *.o
