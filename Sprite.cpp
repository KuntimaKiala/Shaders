#include "Sprite.h"


Sprite::Sprite(){

    this->_vboID = 0 ;
}

Sprite::~Sprite() {

/// freeing the buffer
    if (_vboID != 0){
        std :: cout << "EXIT" << std :: endl ;
        glDeleteBuffers(1, &_vboID) ;
    }

}



void Sprite:: init (float x, float y, float width, float height) {

    this->_x = x;
    this->_y = y;
    this->_width = width ;
    this->_height = height ;

    if (_vboID == 0 ){
        ///Creating the buffer
        glGenBuffers(1, &_vboID) ;
        std :: cout << "_vboID : "<< _vboID << std :: endl ;

    }

    Vertex vertexData[6] ;

    ///First Triangule

    vertexData[0].position.x = _x + _width ;
    vertexData[0].position.y = _y + _height ;

    vertexData[1].position.x  = _x ;
    vertexData[1].position.y  = _y + _height ;

    vertexData[2].position.x  = _x;
    vertexData[2].position.y  = _y ;

    /// Second Triangle

    vertexData[3].position.x  = _x ;
    vertexData[3].position.y  = _y ;

    vertexData[4].position.x  = _x + _width ;
    vertexData[4].position.y  = _y  ;

    vertexData[5].position.x  = _x + _width;
    vertexData[5].position.y  = _y + _height;



    for (int i = 0; i < 6 ; i++){

        vertexData[i].color.r = 255 ;
        vertexData[i].color.g = 0 ;
        vertexData[i].color.b = 255;
        vertexData[i].color.a = 255 ;

    }

    vertexData[1].color.r = 0 ;
    vertexData[1].color.g = 0 ;
    vertexData[1].color.b = 255 ;
    vertexData[1].color.a = 255 ;

    vertexData[4].color.r = 0 ;
    vertexData[4].color.g= 255 ;
    vertexData[4].color.b = 0 ;
    vertexData[4].color.a = 255 ;

    /*vertexData[1].color.r = 0 ;
    vertexData[1].color.g= 0 ;
    vertexData[1].color.b = 255 ;
    vertexData[1].color.a = 255 ;*/



    /// Binding the buffer
    glBindBuffer(GL_ARRAY_BUFFER, _vboID) ; /// activating the buffer
    ///Upload the data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData ,  GL_STATIC_DRAW);


    /// Unbinding the buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0) ;








}
void Sprite::draw() {

   /* glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);*/


    ///Bind buffer
    glBindBuffer(GL_ARRAY_BUFFER, _vboID) ;
    ///Tell OpenGL that we are using a vertex array
    glEnableVertexAttribArray(0) ; /// when not using shader --> glEnableClientState



    /// Specifies the location and data format of an array of vertex coordinates to use when rendering
    /// This is the position  attribute pointer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position)) ; ///when using shader
    /// This is the color  attribute pointer
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color)) ;


    ///Draw the 6 vertices to the screen
    glDrawArrays(GL_TRIANGLES, 0,6) ;
    ///Disable vertex attrib array
    glDisableVertexAttribArray(0) ; ///when using shader
    /// Unbinding the buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0) ;




}
