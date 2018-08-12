#include <Error.h>



void fatalError( std :: string errorString){
            std :: cerr << errorString << std ::endl ;
            //std :: cout << "Enter any key to quit" << std ::endl ;
            std :: cout << "GOOD BYE" <<std ::endl ;
            /*int tmp ;
            std :: cin >> tmp ;*/

            //SDL_DestroyWindow(_window);
            SDL_Quit() ;
            exit(69) ;

        }
