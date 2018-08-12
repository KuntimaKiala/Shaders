#include "GLSLProgram.h"



GLSLProgram::GLSLProgram() : _programID(0), _vertexShaderID(0), _fragementShaderID(0), _numAttribute(0)
{

}

GLSLProgram::~GLSLProgram(){

}


void GLSLProgram:: compileShaders(const std::string& vertexShaderFilePath, const std:: string& fragmentShaderFilePath){


     /// Creating the vertex shader object
    _vertexShaderID = glCreateShader(GL_VERTEX_SHADER); /// it returns a GLuint

    if (_vertexShaderID == 0){
        fatalError("ERROR : vertex shader failed to be created") ;
    }

     /// Creating the fragment shader object
    _fragementShaderID = glCreateShader(GL_FRAGMENT_SHADER); /// it returns a GLuint

    if (_fragementShaderID == 0){
        fatalError("ERROR : fragment shader failed to be created ") ;
    }


    compileShader(vertexShaderFilePath, _vertexShaderID) ;
    compileShader(fragmentShaderFilePath, _fragementShaderID) ;



}


void GLSLProgram::compileShader(const std::string& filePath, GLuint id){


    /// Vertex and fragment shaders are successfully compiled.
    /// Now time to link them together into a program.
    /// Get a program object.
    _programID = glCreateProgram();

/// Uploading the files

    std::ifstream vertexFile(filePath.c_str()); /// create the file and read it
    if (vertexFile.fail()){
        perror(filePath.c_str());
        fatalError("ERROR : Failed to open" + filePath) ;
        fatalError("ERROR : file not created") ;
    }

    std :: string fileContents = "" ; ///  will containt the information to be compiled 'vertex and fragment'
    std :: string line ;

    while (std :: getline(vertexFile, line)){
        fileContents += line +"\n" ; ///To read the new line
    }

    vertexFile.close() ; /// to close the file

    /// Give the source, Will tell the GL where the source is.

    const char* contentsPtr = fileContents.c_str() ;
    glShaderSource(id, 1, &contentsPtr, nullptr) ;

    /// Compiling it the shader
    glCompileShader(id) ;

    ///Error checking
    GLint success = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE){
        GLint maxLength = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

        /// The maxLength includes the NULL character
        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

        /// Provide the infolog in whatever manor you deem best.
        /// Exit with failure.
        glDeleteShader(id); /// Don't leak the shader.

        std :: printf("%s\n", &(errorLog)) ;
        fatalError("ERROR : shader " + filePath + "failed to compile") ;

        return;

    }






}

void GLSLProgram::linkShaders(){



    /// Attach our shaders to our program
    glAttachShader(_programID, _vertexShaderID);
    glAttachShader(_programID, _fragementShaderID);

    /// Link our program
    glLinkProgram(_programID);

    /// Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
    if (isLinked == GL_FALSE){
        GLint maxLength = 0;
        glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

        /// The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(_programID, maxLength, &maxLength, &infoLog[0]);

        // We don't need the program anymore.
        glDeleteProgram(_programID);
        // Don't leak shaders either.
        glDeleteShader(_vertexShaderID);
        glDeleteShader(_fragementShaderID);

        /// Use the infoLog as you see fit.


         std :: printf("%s\n", &(infoLog)) ;
        fatalError("ERROR : shader failed to compile") ;

    }

    /// Always detach shaders after a successful link.
    glDetachShader(_programID, _vertexShaderID);
    glDetachShader(_programID, _fragementShaderID);
    glDeleteShader(_vertexShaderID) ;
    glDeleteShader(_fragementShaderID) ;

}



 void GLSLProgram::addAtttribute(const std :: string& attributeName ){
    ///int index = _numAttribute ;
    ///GLuint program = _programID

    glBindAttribLocation(_programID, _numAttribute++, attributeName.c_str()) ;

 }

GLuint GLSLProgram:: getUniformLocation( const std :: string & uniformeName) {

   GLuint location = glGetUniformLocation(_programID,uniformeName.c_str() ) ;

    if (location == GL_INVALID_INDEX) {
      fatalError("Uniforme" + uniformeName + "Not Found In SHADER") ;
    }
    return location ;
}

void GLSLProgram::use() {

    glUseProgram( _programID);
    /// Enabling the vertex vertexPosition
    for (int i = 0; i < _numAttribute; i++ ){
        glEnableVertexAttribArray(i) ;
    }
}
void GLSLProgram:: unuse() {

    glUseProgram(0);
    /// Disabling the vertex vertexPosition
    for (int i = 0; i < _numAttribute; i++ ){
        glDisableVertexAttribArray(i) ;
    }

}


