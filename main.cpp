#include "Display.h"
#include <iostream>

///Usage : g++ -std=c++11 main.cpp Display.cpp GLSLProgram.cpp  Sprite.cpp -o run -lSDL2 -lGL -lGLEW
int main(int argc, char* argv[]){

    Display display;
    display.run() ;


    return 0 ;
}
