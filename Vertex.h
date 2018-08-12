#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED
#include <GL/glew.h>


struct Position {
        float x, y ;
    }  ;


struct Color {
        GLubyte r;
        GLubyte g;
        GLubyte b;
        GLubyte a;
    }  ;

struct Vertex {

    ///
    Position position ;
    //the same as doing float position[2];



    /// 4 byte for r, g, b color
    Color color ;
    // the same as doing GLubyte color[4];


} ;



#endif // VERTEX_H_INCLUDED
