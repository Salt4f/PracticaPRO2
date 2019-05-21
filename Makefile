OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Diccionario.o Idioma.o Codigo.o FreqTable.o
	g++ -o program.exe program.o Idioma.o Diccionario.o Codigo.o FreqTable.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Diccionario.o: Diccionario.cc Diccionario.hh
	g++ -c Diccionario.cc $(OPCIONS)

Idioma.o: Idioma.cc Idioma.hh
	g++ -c Idioma.cc $(OPCIONS)

Codigo.o: Codigo.cc Codigo.hh
	g++ -c Codigo.cc $(OPCIONS) 

FreqTable.o: FreqTable.cc FreqTable.hh
	g++ -c FreqTable.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.tar
	rm -f *.zip

tar:
	doxygen Doxyfile
	zip -r html.zip ./Documentation/html/
	tar -cvf practica.tar Codigo.cc Codigo.hh Diccionario.cc Diccionario.hh FreqTable.cc FreqTable.hh Idioma.cc Idioma.hh program.cc Makefile html.zip
