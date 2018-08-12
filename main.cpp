/*
Author : Kuntima
Description : Shader
Date : 12/08/2018
Usage :  g++ -std=c++11 main.cpp Display.cpp GLSLProgram.cpp  Sprite.cpp -o run -lSDL2 -lGL -lGLEW
		./run
Note : A lot can be changed, this is nothing more than a prototype that I created to train myself, my goal is to do  3D Game. 
*/

#include "Display.h"
#include <iostream>



int main(int argc, char* argv[]){

    Display display;
    display.run() ;


    return 0 ;
}
