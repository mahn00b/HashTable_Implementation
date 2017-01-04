all: hashmake


hashmake: Main.o HashTable.o Student.o Node.o
	g++ Main.o HashTable.o Student.o Node.o -o hashmake

Main.o: Main.cpp
	g++ -o Main.o -c Main.cpp

HashTable.o: HashTable.cpp
	g++ -o HashTable.o -c HashTable.cpp

Student.o: Student.cpp
	g++ -o Student.o -c Student.cpp

Node.o: Node.cpp
	g++ -o Node.o -c Node.cpp

clean:
	rm *.o hashmake
