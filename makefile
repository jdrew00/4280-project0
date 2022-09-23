CC=g++
CFLAGS=-I.
DEPS = node.h tree.h
OBJ = main.o tree.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
p0: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

.PHONY: clean

clean:
	-rm *.o $(objects)