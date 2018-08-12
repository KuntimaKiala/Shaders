#version 130

//The vertex shader operates on each vertex

//input data from VBO. Each vertex is 2 floats
in vec2 vertexPosition ;
in vec4 vertexColor ;

out vec4 fragmentColor ;
out vec2 fragmentPosition ;

void main(){
   // Set the x,y postion on the screen 
   gl_Position.xy = vertexPosition ;
   // Set the z postion to zero, since 2D
   gl_Position.z = 0.0 ;
   // Indicate that the coordinate are normalized
   gl_Position.w =  1 ;
   fragmentPosition = vertexPosition ;
   fragmentColor = vertexColor ; 
 }
