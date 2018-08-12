#ifndef SPRITE_H
#define SPRITE_H
#include <GL/glew.h>
#include <iostream>
#include "Vertex.h"
#include <cstddef>

class Sprite
{
    public:
        Sprite();
        ~Sprite();
        void init (float x, float y, float width, float height) ;
        void draw() ;
    protected:
    private:

        float _x;
        float _y;
        float _width;
        float _height ;
        GLuint _vboID ;
};

#endif // SPRITE_H
