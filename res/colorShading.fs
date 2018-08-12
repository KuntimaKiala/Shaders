#version 130 
// The fragment shader operates on each pixel
//in a given polygon

in vec2  fragmentPosition ;
in vec4 fragmentColor ;
// This is a 
//3 component float vector that gets outputted to the screen 

out vec4 color ;

uniform float time ;

void main (){

	//Just hardcore the color
	color =  vec4(fragmentColor.r*(cos(fragmentPosition.x*4.0  + time)+1.0)*0.5, 
		      fragmentColor.g*(sin(fragmentPosition.y*8.0  + time)+1.0)*0.5,
		      fragmentColor.b*(cos(fragmentPosition.x*2.  + time)+1.0)*0.5,
		      fragmentColor.a) ;


}
