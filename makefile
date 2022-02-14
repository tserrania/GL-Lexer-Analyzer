OBJ= lexer.o symbole.o automate.o etat.o etats.o
COMP= g++

parser: main.o $(OBJ)
	$(COMP) -o parser main.o $(OBJ)

test: test.o $(OBJ)
	$(COMP) -o test test.o $(OBJ)

main.o: main.cpp
	$(COMP) -c main.cpp -o main.o

test.o: test.cpp
	$(COMP) -c test.cpp -o test.o

%.o: %.cpp
	$(COMP) -c $^ -o $@

clean:
	rm *.o parser test