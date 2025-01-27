CC = gcc
CFLAGS = -Wall -g
OBJ = main.o process_list.o memory_usage.o process_termination.o
EXEC = system_monitor

# Default target to build the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Rule to compile main.c
main.o: main.c process_list.h memory_usage.h process_termination.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# Rule to compile process_list.c
process_list.o: process_list.c process_list.h
	$(CC) $(CFLAGS) -c process_list.c -o process_list.o

# Rule to compile memory_usage.c
memory_usage.o: memory_usage.c memory_usage.h
	$(CC) $(CFLAGS) -c memory_usage.c -o memory_usage.o

# Rule to compile process_termination.c
process_termination.o: process_termination.c process_termination.h
	$(CC) $(CFLAGS) -c process_termination.c -o process_termination.o

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)