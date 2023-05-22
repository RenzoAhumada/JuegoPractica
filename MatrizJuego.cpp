#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

std::string characters[4][4] = {

    ///Matriz de los personajes para poder seleccionar

    {"Mario","Luigi","Peach"},
    {"Bowser","Wario","Waluigi"},
    {"Pikachu", "Charmander", "Bulbalsur"},
    {"Donkey Kong", "Didie Kong", "Dixie Kong"}

};
std::string viewerCharacter(int files, int columns){

    ///Logica para adivinar el personaje segun las selecciones del jugador
    if (files>=0 && files<4 && columns>=0 && columns<4)
    {
    return characters[files][columns];
    }else{
        ///En caso que el jugador no selecione o de malas indicaciones
        cout<<"¡¡¡Tenias que elegir un personaje y no elegiste nada!!!"<<std::endl;
    }


};

void viewCharacter();
int playGame(int files, int columns);


int main() {
    ///Se iguala la opcion a 1 para que asi pueda ingresar al bucle while
    int option=1;

    std:: cout<< "Bienvenido al juego de adivinanza"<< std:: endl;
    std:: cout<< "¿Podre adivinar tu personaje?"<< std:: endl;


    while(option=1){
    ///Desde aqui llamaremos las funciones para poder mostrar los personajes a utilizar
    // Y tendremos la funcion que nos enviara al juego para poder mostrarlo
    int files=0, columns=0;
    viewCharacter();
    playGame(files, columns);
    //Desde aqui mostraremos si se repite el bucle del juego o se termina
    std:: cout<< "¿Te gustaria volver a intentarlo?"<< std:: endl;
    std:: cout<< "1 para seguir o 0 para terminar el juego"<< std:: endl;
    cin>>option;

        while (option<1 && option>0)
        {
            if(option<1 && option>0)
            {
                std:: cout<< "Necesito una opcion correcta, vuelve a intentar"<< std:: endl;
                cin>>option;
            }
        }
        
    }

}


void viewCharacter() {
    //Con esta simple funcion mostraremos por pantalla nuestra matriz de personajes
    //Se la llama con un void ya que solo queremos que nos muestre por pantalla los personajes no necesitamos una devolucion
    cout<<"Los personajes disponibles son"<< std::endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << "[" << i << "][" << j << "]: " << characters[i][j] << std::endl;
        }
    }

}

int playGame(int files, int columns){
    //Desde aqui manejaremos la logica del juego y las afirmaciones, devolviendo y retornando valores para la adivinanza
    int option;
    std::cout << "Utilizando el numero 1 para afirmar" << std::endl;
    std::cout << "Utilizando el numero 0 para negar, jugaremos y adivire su personaje." << std::endl;
    std::cout << "¿Preparado?" << std::endl;
    cout<<"¿Su personaje es del mundo champignon?"<<std::endl;
    cin>>option;
    if (option==1)
    {
        std:: cout<< "¿Su personaje es de los buenos?"<< std:: endl;
        cin>> option;
        if(option==1){
            std:: cout<< "¿Utiliza una gorra simpatica?"<< std:: endl;
            cin>>option;
            if(option==1){
                std:: cout<< "¿Es de color roja?"<< std:: endl;
                cin>> option;
                if(option==1){
                    files=0;
                    columns=0;
                  
                }
                if(option==0){
                    std:: cout<< "¿Es el hermano verde verdad?"<< std:: endl;
                    files=0;
                    columns=1;
                    
                }
            }
            if (option==0){
                std:: cout<< "¿Sera la princesa?"<< std:: endl;
                files=0;
                columns=2;
                
            }
        }
        
    ///¡¡¡¡¡¡Desde aca esta el error!!!!!!!
        if (option==0){
            std:: cout<< "¿Es la parte mala de nuestro buen fontanero rojo?"<< std:: endl;
            if(option=1){
                files=1;
                columns=1;
                
            }
            if(option==0){
                std:: cout<< "¿Escupe fuego por la boca y se deja caer en la lava?"<< std:: endl;
                if(option=1){
                    std:: cout<< "¿El rey coopa?"<< std:: endl;
                    files=1;
                    columns=0;
                    
                }
                if(option==0){
                    std:: cout<< "Pobre le deberian haber dado mejor papel a tu personaje"<< std:: endl;
                    files=1;
                    columns=2;
                  
                }
            }
        }
        
    }if (option==0){
        std:: cout<< "Su personaje ¿Lo utilizan para las batallas?"<< std:: endl;
        cin>> option;
        if(option==1){
        std:: cout<< "¿Es de color amarillo?"<< std:: endl;
        cin>>option;
            if(option==1){
            files=2;
            columns=0;
           
            } 
            if(option==0){
                std:: cout<< "¿Nos podria llegar a quemar este personaje?"<< std:: endl;
                cin>>option;
                if(option==1){
                files=2;
                columns=1;
                
                }
                if(option==0){
                files=2;
                columns=2;

                }
            }
            
        }
        option=1;
        
    }if (option==0){
        std:: cout<< "Su personaje¿Es el gorilla que aparecio peleando con Mario?"<< std:: endl;
        cin>>option;
        if(option==1){
            files=3;
            columns=0;
            
        }
        if(option==0){
        std:: cout<< "Su personaje ¿Es un simio que utiliza una gorra?"<< std:: endl;
        cin>>option;
        if(option==1){
            files=3;
            columns=1;
           
            if(option==0){
                files=3;
                columns=2;
              
            }
        }
        }
    }
    else{
        files=NULL;
        columns=NULL;
    }
    std::string selecCharacter = viewerCharacter(files, columns);

    std:: cout<<"Su personaje es: "<< selecCharacter << std::endl;

return 0;
}

