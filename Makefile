OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o Diccionario.o Idioma.o
	g++ -o program.exe main.o Idioma.o Diccionario.o

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

Diccionario.o: Diccionario.cc Diccionario.hh
	g++ -c Diccionario.cc $(OPCIONS)

Idioma.o: Idioma.cc Idioma.hh
	g++ -c Idioma.cc $(OPCIONS)

Codigo.o: Codigo.cc Codigo.hh
	g++ -c Codigo.cc $(OPCIONS) 

clean:
	rm -f *.o
	rm -f *.exe
