# specifies the compiler
CC = gcc

# -Wall	turns on most compiler warnings
# -g 	enables debugging info
CFLAGS = -Wall -g -DNDEBUG

# specifies name of executable
TARGET = ex19

# what the 'make all' command executes when used
# list the dependencies after the colon in the order
# you want them to execute
all: clean other $(TARGET)

	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

other:

	echo "This is another dependency on which all is based"

# what 'make clean' command executes
clean:

	$(RM) $(TARGET)


