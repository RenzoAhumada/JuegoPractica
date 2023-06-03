#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;


///Se crea la matriz con los personajes predefinidos
string characters[4][3] = {
    {"Mario", "Luigi", "Peach"},
    {"Bowser", "Wario", "Waluigi"},
    {"Pikachu", "Charmander", "Bulbasaur"},
    {"Donkey Kong", "Diddy Kong", "Dixie Kong"}
};
///Estructura para poder crear jugadores y poder darles los puntos
struct PLAYERS
{
    char name[20];
    int points;
};

string viewerCharacter(int row, int column) {
    // Lógica para mostrar el personaje seleccionado por el jugador
    if (row >= 0 && row < 4 && column >= 0 && column < 3) {
        return characters[row][column];
    } else {
        // En caso de que el jugador no seleccione o proporcione coordenadas incorrectas
        return "Personaje no válido";
    }
}
void worldMario(int& option);
void worldDonkeyKong(int& option);
void worldPokemon(int& option);
void viewCharacter() {
    // Esta función muestra por pantalla la matriz de personajes
    cout << "Los personajes disponibles son:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "[" << i << "][" << j << "]: " << characters[i][j] << endl;
        }
    }
}
void posibleCharacters(){
///Con esta funcion se mostraran segun las opciones los personajes posibles que pueden ser


}
void playGame() {
///Desde aqui partimos en el juego teniendo 3 tipos de funciones segun la respuesta del jugador
    int option;
    srand(time(0));
    option = (rand() % 3) + 1;

    while (option!=0){
    switch (option) {
        case 1:
            worldMario(option);
            ///Si el caso de la funcion 1 no es el personaje a option se le suma ++ para que comience parte hacia el siguiente caso
            break;
        case 2:
            worldDonkeyKong(option);
            break;
        case 3:
            worldPokemon(option);
            break;  
    }
    }
}

void worldDonkeyKong(int& option) {
    ///Funcion del mundo de donkey kong
    char yesOrNo;
    cout << "¿Su personaje es del mundo de Donkey Kong? ";
    cin >> yesOrNo;

    if (toupper(yesOrNo) == 'S') {
        // Aquí deberías agregar la lógica para el mundo de Donkey Kong si la respuesta es "Sí"
        option = 0;

    } else if (toupper(yesOrNo) == 'N') {
        option++;  // Incrementa option en 1 si la respuesta es "No"

    } else {
        cout << "Opción no válida";
    }
}

void worldMario(int& option) {
    ///Funcion para mundo mario
    char yesOrNo;
    cout << "¿Su personaje es del mundo de Mario? ";
    cin >> yesOrNo;

    if (toupper(yesOrNo) == 'S') {
        option = (rand() % 2) + 1;
        ///igual que la funcion de playgame se da un random para ver si elije 1 o 2 para el caso correspondiente
        switch (option) {
            case 1:
                cout << "¿Su personaje es de los buenos? ";
                cin >> yesOrNo;
                if (toupper(yesOrNo) == 'S') {
                    cout << "¿Su personaje lleva una gorra roja? ";
                    cin >> yesOrNo;
                    if (toupper(yesOrNo) == 'S') {
                        int row = 0, column = 0;
                        string selectedCharacter = viewerCharacter(row, column);
                        cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                        option=0;
                    }else if(yesOrNo='N'){
                        cout<<"¿Tu personaje es el hermano menor?";
                        cin>>yesOrNo;
                        if(toupper(yesOrNo='S')){
                            int row = 0, column = 1;
                            string selectedCharacter = viewerCharacter(row, column);
                            cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                            option=0;
                        }else{
                            row=0, column=2;
                            string selectedCharacter = viewerCharacter(row, column);
                            cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                            option=0;
                        }
                    }
                }else if(toupper(yesOrNo='N')){
                    option++;
                } 
                
                break;
            case 2:
                cout << "¿Su personaje es de los villanos? ";
                cin >> yesOrNo;
                if (toupper(yesOrNo) == 'S') {
                    cout << "¿Su personaje es la parte contraria de los hermanos bros? ";
                    cin >> yesOrNo;
                    if(toupper(yesOrNo='S')){
                        cout<<"¿Su personaje es la parte mala del personaje principal de la historia?";
                        cin>>yesOrNo;
                        if (yesOrNo='S')
                        {
                            row=1, column=1;
                            string selectedCharacter = viewerCharacter(row, column);
                            cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                            option=0;
                        }else if (yesOrNo='N')
                        {
                            row=2, column=2;
                            string selectedCharacter = viewerCharacter(row, column);
                            cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                            option=0;
                        }else{
                            cout<<"Volvamos a empezar ya que se ve que no elegiste ningun personaje";
                            option =(rand()%3+1);
                        }
                    }else if(toupper(yesOrNo='N')){
                        cout<<"¿Su personaje aparece en el primer juego como villano principal?";
                        cin>>yesOrNo;
                        if (toupper(yesOrNo='S'))
                        {
                            row=0, column=1;
                            string selectedCharacter = viewerCharacter(row, column);
                            cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                            option=0;
                        }else{
                            cout<<"Volvamos a empezar ya que se ve que no elegiste ningun personaje";
                            option =(rand()%3+1);
                        }
                    }
                    }else if(toupper(yesOrNo='N')){
                        option++;
                    }
                break;
           
    } else if (toupper(yesOrNo) == 'N') {
        option++;
    } else {
        cout << "Opción no válida" << endl;
    }
}}

void worldPokemon(int& option) {
    ///funcion si el personaje es de pokemon
    char yesOrNo;
    cout << "¿Su personaje es del mundo de Pokémon? ";
    cin >> yesOrNo;

    if (toupper(yesOrNo) == 'S') {
        srand(time(0));
        ///misma forma de optimizar el juego se utiliza un random para darle mas aleatoridad al juego
        option = (rand() % 3) + 1;
        switch(option){
        case 1:
            cout<<"¿Su personaje es de tipo electrico?"
            cin>>yesOrNo;
            if (toupper(yesOrNo='S'))
            {
                row=2, column=0;
                string selectedCharacter = viewerCharacter(row, column);
                cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                option=0;
            }else if(toupper(yesOrNo='N')){
                option++;
            }else{
                option++;
            }
            break;
        case 2:
            cout<<"¿Su peresonaje es de tipo fuego?"
            cin>>yesOrNo;
            if (toupper(yesOrNo='S'))
            {
                row=2, column=1;
                string selectedCharacter = viewerCharacter(row, column);
                cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                option=0;
            }else if(toupper(yesOrNo='N')){
                option++;
            }else{
                option++;
            }
            break;
        case 3:
            cout<<"¿Su personaje es de tipo hierba?"
            cin>>yesOrNo;
            if (toupper(yesOrNo='S'))
            {
                row=2, column=2;
                string selectedCharacter = viewerCharacter(row, column);
                cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                option=0;
            }else if(toupper(yesOrNo='N')){
                option++;
            }else{
                option++;
            }
            break;
        }



    } else if (toupper(yesOrNo) == 'N') {
        option = 1;  // Incrementa option en 1 si la respuesta es "No"

    } else {
        cout << "Opción no válida";
    }}

void createPlayers(int *n, struct PLAYERS v[]) {
    ///Desde aqui se crea la estrucutura de los jugadores
    cout << "Ingrese la cantidad de jugadores: " << endl;
    cin >> *n;

    for (int i = 0; i < *n; ++i) {
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> v[i].name;
        v[i].points = 0;
    }
}

int main() {
    ///Main limpio que mostrar el personaje y enviaran los datos para el juego
    srand(time(NULL));

    int row, column, n;
    struct PLAYERS player[10];
    createPlayers(&n, player);
    viewCharacter();
    playGame();
    string selectedCharacter = viewerCharacter(row, column);
    cout << "Tu personaje es: " << selectedCharacter << endl;
    return 0;
}