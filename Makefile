


output: main.o Display.o Error.o GLSLProgram.o Sprite.o
	g++ -std=c++11 main.o Display.o Error.o GLSLProgram.o Sprite.o -lSDL2 -o ouput


main.o: main.cpp
	g++ -c main.cpp

Display.o: Display.cpp Display.h
	g++ -c Display.cpp  

Error.o: Error.cpp Error.h
	g++ -c Error.cpp

GLSLProgram.o: GLSLProgram.cpp GLSLProgram.h
	g++ -c GLSLProgram.cpp

Sprite.o: Sprite.cpp Sprite.h
	g++ -c Sprite.cpp
