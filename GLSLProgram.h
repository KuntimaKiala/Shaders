#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <Error.h>
#include <fstream>
#include <vector>

/// Note : GLSL is need to openGL to run (write and read) thing on the GPU
class GLSLProgram
{
    public:
        GLSLProgram();
        ~GLSLProgram();

        /// read the file from the path and compiles it
        void compileShaders(const std::string& vertexShaderFilePath, const std:: string& fragmentShaderFilePath) ;
        /// link the shader in the final program
        void linkShaders() ;
        /// binding attribute
         void addAtttribute(const std :: string& attributeName );
         GLuint getUniformLocation( const std :: string & uniformeName) ;

         /// usage of the program
        void use() ;
        void unuse() ;

    private:
        GLuint _programID ; /// ID that refers to entire program
        GLuint _vertexShaderID ; /// ID that refers to entire vertex shader
        GLuint _fragementShaderID ; /// ID that refers to entire fragment shader
        void compileShader(const std::string& filePath, GLuint id);
        int _numAttribute ;
};

#endif // GLSLPROGRAM_H
