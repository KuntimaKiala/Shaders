#include "Display.h"



Display::Display(){
    this->_window = nullptr;
    this-> _renderer = nullptr;
    this->_screenWidth =  500;
    this->_screenHeigth = 500;
    Display::_gameState = GameState :: PLAY ;
    _time = 0 ;

}

Display::~Display(){
    //dtor
}



void Display::run(){

    initSystems() ;
    _sprite.init(-1.0f,-1.0f,2.0f,2.0f) ;
    gameLoop();
}
void Display::initSystems() {

    ///Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING) ;
    /// Create the window
    _window = SDL_CreateWindow("GAME OVER", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeigth, SDL_WINDOW_OPENGL) ;
    if (_window == nullptr){
        fatalError("ERROR : SDL Could Not Be Openned") ;

    }
    else{

        /// Set up the OpenGL
        /// Create an OpenGL context associated with the window.
        SDL_GLContext glContext = SDL_GL_CreateContext(_window) ;

        if (glContext == nullptr){
            fatalError("SDL context could not be Openned") ;
        }
        /// Set up glew
        GLenum status = glewInit() ;
        if (status != GLEW_OK){
            fatalError("GLEW Failed") ;
        }

        ///Create a double buffered window
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1) ;
        ///Set up the color
        glClearColor(1.0f,0.0f,.0f,1.0f);

        /*glDisable(GL_CULL_FACE) ;*/
        std :: printf("\n*** OpenGL Version: %s ***\n", glGetString(GL_VERSION)) ;

        ///initializing the shaders
       initShaders() ;

    }


}

void Display:: initShaders(){

    _colorShaderProgram.compileShaders("res/colorShading.vs", "res/colorShading.fs") ;
    _colorShaderProgram.addAtttribute("vertexPosition") ;
    _colorShaderProgram.addAtttribute("vertexColor") ;
    _colorShaderProgram.linkShaders() ;

}

void Display::gameLoop(){

    GLenum err = glGetError() ;
    if ((glGetError()) != (GL_NO_ERROR)){
        std :: cout << "OPENGL ERROR"<< std :: endl ;
        std::cerr << glewGetErrorString(glGetError()) << std :: endl ;

    }
    while (_gameState != GameState :: EXIT){
        processInput() ;
        _time += 0.05 ;
        drawGame();
    }

}
void Display::processInput(){


    while (SDL_PollEvent(&_event)){
        switch (_event.type){
            case SDL_QUIT :
                _gameState = GameState :: EXIT ;
                break;

            case SDL_MOUSEMOTION :
                std :: cout <<"X : "<< _event.motion.x <<"\n"  <<"Y : "<< _event.motion.y << std :: endl;
                break ;


        }
    }

}


/// Draws the game with OpenGL
 void Display::drawGame(){

    ///Set base depth to 1.0
    glClearDepth(1.0);
    /// Clear the color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;

    _colorShaderProgram.use() ;

    GLuint timeLocation  = _colorShaderProgram.getUniformLocation("time") ;
    glUniform1f(timeLocation, _time);
    _sprite.draw() ;
    _colorShaderProgram.unuse() ;

    /// Swap the buffer and draw eveerything to the screen
    SDL_GL_SwapWindow(_window) ;

 }



