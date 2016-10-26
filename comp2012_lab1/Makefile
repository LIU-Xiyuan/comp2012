all: purpleProgram.exe cyanProgram.exe

purpleProgram.exe: purpleMain.o red.o blue.o
	g++ -o purpleProgram.exe purpleMain.o red.o blue.o

purpleMain.o: purpleMain.cpp red.h blue.h
	g++ -c purpleMain.cpp

cyanProgram.exe: cyanMain.o green.o blue.o
	g++ -o cyanProgram.exe cyanMain.o green.o blue.o
	
cyanMain.o: cyanMain.cpp green.h blue.h
	g++ -c cyanMain.cpp

red.o: red.cpp red.h
	g++ -c red.cpp 

green.o: green.cpp green.h
	g++ -c green.cpp 

blue.o: blue.cpp blue.h
	g++ -c blue.cpp 

clean:
	rm -rf *.o
	rm -rf *.exe