OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o idioma.o diccionario.o
	g++ -o program.exe main.o idioma.o diccionario.o

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

diccionario.o: diccionario.cc diccionario.hh
	g++ -c diccionario.cc $(OPCIONS)

idioma.o: idioma.cc idioma.hh
	g++ -c idioma.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
