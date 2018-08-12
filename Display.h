#ifndef DISPLAY_H
#define DISPLAY_H
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include "Sprite.h"
#include "GLSLProgram.h"
#include "Error.h"

enum class GameState {PLAY, EXIT} ;
class Display
{
    public:
        Display();
        ~Display();
        void run();


    private:
        SDL_Window* _window ;
        SDL_Renderer* _renderer ;
        int _screenWidth ;
        int _screenHeigth ;
        void initSystems() ;
        void gameLoop();
        void processInput();
        GameState _gameState ;
        SDL_Event _event ;
        void drawGame();
        Sprite _sprite ;
        GLSLProgram _colorShaderProgram ;
        void initShaders() ;
        float _time ;

};

#endif // DISPLAY_H

