# Shaders
A simple program that display a window using SDL/OpenGL, the color of the window change with time, it tell also the location of the mouse in the window displayed.

# Packages : 
	    SDL2
	    GL 
	    GLEW

make sure all the required package are installed before compiling

# Usage : 
	
	g++ -std=c++11 main.cpp Display.cpp GLSLProgram.cpp  Sprite.cpp -o run -lSDL2 -lGL -lGLEW
	                 if cmake is installed, in terminal type make	
