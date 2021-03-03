CC = gcc

CFLAGS = -Wall -g -DNDEBUG

COMMON = ex22
TARGET = ex22_main

all: clean first ${TARGET}
	${CC} ${CFLAGS} ${TARGET}.c ${COMMON}.o -o ${TARGET}

first:
	${CC} ${CFLAGS} -c -o ${COMMON}.o ${COMMON}.c

clean:
	rm -f ex22_main *.o
