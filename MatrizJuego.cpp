#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

std::string characters[3][3] = {

    {"mario","luigi","peach"},
    {"bowser","Wario","Waluigi"},
    {"Pikachu", "Charmander", "Bulbalsur"}

};
std::string viewerCharacter(int files, int columns){
    if (files>=0 && files<3 && columns>=0 && columns<3)
    {
    return characters[files][columns];
    }else{
        cout<<"¡¡¡Tenias que elegir un personaje y no elegiste nada!!!";
    }


};

void viewCharacter();
int playGame(int files, int columns);


int main() {
    int files=0, columns=0;
    viewCharacter();
    playGame(files, columns);
}


void viewCharacter() {

    cout<<"Los personajes disponibles son";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << "[" << i << "][" << j << "]: " << characters[i][j] << std::endl;
        }
    }

}

int playGame(int files, int columns){
    int option=1;
    cout<<"Su personaje usa gorra roja??";
        cin>>option;
    if (option=0)
    {
        files=0;
        columns=0;
    }
    std::string selecCharacter = viewerCharacter(files, columns);

    std:: cout<<"Su personaje es: "<< selecCharacter;

return 0;
}

