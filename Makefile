


output: main.o Display.o Error.o GLSLProgram.o Sprite.o
	g++ -std=c++11 main.o Display.o Error.o GLSLProgram.o Sprite.o -o ouput -lSDL2 -lGL -lGLEW


main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Display.o: Display.cpp Display.h
	g++ -std=c++11 -c Display.cpp  

Error.o: Error.cpp Error.h
	g++ -std=c++11 -c Error.cpp

GLSLProgram.o: GLSLProgram.cpp GLSLProgram.h
	g++ -std=c++11 -c GLSLProgram.cpp

Sprite.o: Sprite.cpp Sprite.h
	g++ -std=c++11 -c Sprite.cpp
