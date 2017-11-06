CC=g++
OBJECTS= main.o
EXE=prog5

$(EXE):		$(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS)
main.o:		main.cpp graph.h
		$(CC) -c main.cpp 

clean:
		rm -rf prog5 *~ $(OBJECTS) $(EXE)
