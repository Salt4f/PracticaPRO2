OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o arbol.o idioma.o
	g++ -o program.exe main.o arbol.o idioma.o

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

arbol.o: arbol.cc arbol.hh
	g++ -c arbol.cc $(OPCIONS)

idioma.o: idioma.cc idioma.hh
	g++ -c idioma.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
