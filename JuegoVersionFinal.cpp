#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
///Matriz para personajes a elegir
string characters[4][3] = {
    {"Mario", "Luigi", "Peach"},
    {"Bowser", "Wario", "Waluigi"},
    {"Pikachu", "Charmander", "Bulbasaur"},
    {"Donkey Kong", "Diddy Kong", "Dixie Kong"}
};
///Estructura de los jugadores
struct Player
{
    char name[20];
    int points;
};
///Desde esta funcion llamaremos al personaje para adivinar
string viewerCharacter(int row, int column) {
    if (row >= 0 && row < 4 && column >= 0 && column < 3) {
        return characters[row][column];
    } else {
        return "Personaje no válido";
    }
}
///Firmas
void worldMario(int& option);
void worldDonkeyKong(int& option);
void worldPokemon(int& option);
void playForGoodChararctersMario(int& option);
void playForBadCharactersMario(int& option);
void rulersGame();
void menu();

///Funcion donde mostraremos los personajes disponibles que nos quedan
void viewCharacter() {
    cout << "Los personajes disponibles son:" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "[" << i << "][" << j << "]: " << characters[i][j] << endl;
        }
    }
}
///Logica del juego donde tira un random para la pregunta mas randomizada
void playGame() {
    int option;
    cout<<"Para afirmar las preguntas presione 'S' y para negarla presione 'N'. ";
    srand(time(0));
    option = (rand() % 3) + 1;
    while (option != 0) {
        switch (option) {
            case 1:
                worldMario(option);
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
///Logica funcion para mundo de donkeykong
void worldDonkeyKong(int& option) {
  char yesOrNo;
    int row, column, optionTwo;
    cout << "¿Su personaje es del mundo de donkeykong? ";
    cin >> yesOrNo;

    if (toupper(yesOrNo) == 'S') {
        cout<<"Los posibles personajes a elegir son: Donkey Kong, Diddy Kong, Dixie Kong"<<endl;
        srand(time(0));
        optionTwo = (rand() % 3) + 1;
        switch (optionTwo) {
            case 1:
                cout << "¿Su personaje es el mas fuerte de los 3? ";
                cin >> yesOrNo;
                if (toupper(yesOrNo) == 'S') {
                    row = 3;
                    column = 0;
                    string selectedCharacter = viewerCharacter(row, column);
                    cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                    option = 0;
                } else if (toupper(yesOrNo) == 'N') {
                    optionTwo++;
                }
                break;
            case 2:
                cout << "¿Su personaje es el hermano pequeño que lleva una gorra? ";
                cin >> yesOrNo;
                if (toupper(yesOrNo) == 'S') {
                    row = 3;
                    column = 1;
                    string selectedCharacter = viewerCharacter(row, column);
                    cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                    option = 0;
                } else if (toupper(yesOrNo) == 'N') {
                    optionTwo++;
                }
                break;
            case 3:
                cout << "¿Su personaje es la hermana de los gorilas? ";
                cin >> yesOrNo;
                if (toupper(yesOrNo) == 'S') {
                    row = 3;
                    column = 2;
                    string selectedCharacter = viewerCharacter(row, column);
                    cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                    option = 0;
                } else if (toupper(yesOrNo) == 'N') {
                    optionTwo=1;
                }
                break;
        }
    } else if (toupper(yesOrNo) == 'N') {
        option++;
    }else{
        cout<<"Papi ¿hablo en chino? te dije que S para afirmar o N para negar no es dificil";
        option=2;
    }
}

///funcion para mundo mario
void playForGoodChararctersMario(int& option, int optionTwo){
    int row, column;
    char yesOrNo;
    cout << "¿Su personaje es de los buenos? ";
                cin >> yesOrNo;
                if (toupper(yesOrNo) == 'S') {
                    cout<<"Los posibles personajes a elegir son: Mario, Luigi, Peach";
                    cout << "¿Su personaje lleva una gorra roja? ";
                    cin >> yesOrNo;
                    if (toupper(yesOrNo) == 'S') {
                        row = 0;
                        column = 0;
                        string selectedCharacter = viewerCharacter(row, column);
                        cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                        option = 0;
                    } else if (toupper(yesOrNo) == 'N') {
                        cout << "¿Tu personaje es el hermano menor? ";
                        cin >> yesOrNo;
                        if (toupper(yesOrNo) == 'S') {
                            row = 0;
                            column = 1;
                            string selectedCharacter = viewerCharacter(row, column);
                            cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                            option = 0;
                        } else {
                            row = 0;
                            column = 2;
                            string selectedCharacter = viewerCharacter(row, column);
                            cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                            option = 0;
                        }
                    }
                } else if (toupper(yesOrNo) == 'N') {
                    optionTwo = 2;
                }
}
///Funcion para mundo mario
void playForBadCharactersMario(int& option, int optionTwo){
    int row, column;
    char yesOrNo;
     cout << "¿Su personaje es de los villanos? ";
                cin >> yesOrNo;
                if (toupper(yesOrNo) == 'S') {
                    cout<<"Los posibles personajes a elegir son: Bowser, Wario, Waluigi"<<endl;
                    cout << "¿Su personaje es la parte contraria de los hermanos bros? ";
                    cin >> yesOrNo;
                    if (toupper(yesOrNo) == 'S') {
                        cout << "¿Su personaje es la parte mala del personaje principal de la historia? ";
                        cin >> yesOrNo;
                        if (toupper(yesOrNo) == 'S') {
                            row = 1;
                            column = 1;
                            string selectedCharacter = viewerCharacter(row, column);
                            cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                            option = 0;
                        } else if (toupper(yesOrNo) == 'N') {
                            row = 2;
                            column = 2;
                            string selectedCharacter = viewerCharacter(row, column);
                            cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                            option = 0;
                        } else {
                            cout << "Volvamos a empezar ya que no elegiste ningún personaje." << endl;
                            option = (rand() % 3) + 1;
                        }
                    } else if (toupper(yesOrNo) == 'N') {
                        cout << "¿Su personaje aparece en el primer juego como villano principal? ";
                        cin >> yesOrNo;
                        if (toupper(yesOrNo) == 'S') {
                            row = 0;
                            column = 1;
                            string selectedCharacter = viewerCharacter(row, column);
                            cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                            option = 0;
                        } else {
                            cout << "Volvamos a empezar ya que no elegiste ningún personaje." << endl;
                            option = (rand() % 3) + 1;
                        } 
        }
    }else if(toupper(yesOrNo)=='N'){
        optionTwo=1;
    } 
}
///Funcion de mundo mario donde llamaremos un random para ver si es un personaje bueno o malo
void worldMario(int& option) {
    char yesOrNo;
    int optionTwo;
    cout << "¿Su personaje es del mundo de Mario? ";
    cin >> yesOrNo;

    if (toupper(yesOrNo) == 'S') {
        cout<<"Los posibles personajes a elegir son: Mario, Luigi, Peach, Bowser, Wario, Waluigi"<<endl;
        optionTwo = (rand() % 2) + 1;
        switch (optionTwo) {
            case 1:
                playForGoodChararctersMario(option, optionTwo);
                break;
            case 2:
                playForBadCharactersMario(option, optionTwo);
                break;
        }
    }else if(toupper(yesOrNo)=='N'){
        option++;
    }else{
        cout<<"Papi ¿hablo en chino? te dije que S para afirmar o N para negar no es dificil";
        option=1;
    }
}
///Funcion mundo pokemon
void worldPokemon(int& option) {
    char yesOrNo, afirmation;
    int row, column, optionTwo;
    cout << "¿Su personaje es del mundo de Pokémon? ";
    cin >> yesOrNo;

    if (toupper(yesOrNo) == 'S') {
        cout<<"Los posibles personajes a elegir son: Pikachu, Charmander, Bulbasaur"<<endl;
        srand(time(0));
        optionTwo = (rand() % 3) + 1;
        switch (optionTwo) {
            case 1:
                cout << "¿Su personaje es de tipo eléctrico? ";
                cin >> afirmation;
                if (toupper(afirmation) == 'S') {
                    row = 2;
                    column = 0;
                    string selectedCharacter = viewerCharacter(row, column);
                    cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                    option = 0;
                } else if (toupper(afirmation) == 'N') {
                    optionTwo++;
                }
                break;
            case 2:
                cout << "¿Su personaje es de tipo fuego? ";
                cin >> afirmation;
                if (toupper(afirmation) == 'S') {
                    row = 2;
                    column = 1;
                    string selectedCharacter = viewerCharacter(row, column);
                    cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                    option = 0;
                } else if (toupper(afirmation) == 'N') {
                    optionTwo++;
                }
                break;
            case 3:
                cout << "¿Su personaje es de tipo planta? ";
                cin >> afirmation;
                if (toupper(afirmation) == 'S') {
                    row = 2;
                    column = 2;
                    string selectedCharacter = viewerCharacter(row, column);
                    cout << "¡Adiviné! Tu personaje es " << selectedCharacter << "." << endl;
                    option = 0;
                } else if (toupper(afirmation) == 'N') {
                    optionTwo=1;
                }
                break;
        }
    } else if (toupper(yesOrNo) == 'N') {
        option=1;
    }else{
        cout<<"Papi ¿hablo en chino? te dije que S para afirmar o N para negar no es dificil";
        option=3;
    }
}
///Desde esta funcion creamos los jugadores con nombres y la cantidad de jugadores
void createPlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Ingrese el nombre del jugador " << (i + 1) << ": ";
        cin.ignore();
        cin.getline(players[i].name, 20);
        players[i].points = 0;
    }
}
void rulersGame() {
    cout << "Mira papa las reglas super sencillas" << endl;
    cout << "Para Afirmas presionas la S, esto hace que la pregunta vaya a un codigo de linea siguiente para seguir el juego" << endl;
    cout << "Para negar con la N, eso quiere decir que si queres presionar cualquier otra tecla no funciona" << endl;
    cout << "Enserio no presiones otra tecla, es muy simple el juego" << endl;
    cout << "Cualquier cosa que no lo entiendas puedes volver a mirar las reglas aquí" << endl;
}

void menu() {
    int option;
    cout << "Bienvenido al juego de adivina el personaje." << endl;
    cout << "Para empezar ingrese 1" << endl;
    cout << "Para ver las reglas presione 2" << endl;
    cout << "Para terminar el juego presione 0" << endl;
    
    while (true) {
        cin >> option;
        
        switch (option) {
            case 1: {
                int numPlayers;
                cout << "Ingrese la cantidad de jugadores: ";
                cin >> numPlayers;
                Player players[numPlayers];
                createPlayers(players, numPlayers);
                playGame();
                break;
            }
            case 2: {
                rulersGame();
                break;
            }
            case 0: {
                cout << "Nos vimos padre" << endl;
                return;
            }
            default: {
                cout << "Amigo, es 1, 2 o 0, no presiones otra cosa que no funciona y puedes romper el juego" << endl;
                break;
            }
        }
        
        cout << "Para empezar ingrese 1" << endl;
        cout << "Para ver las reglas presione 2" << endl;
        cout << "Para terminar el juego presione 0" << endl;
    }
}

int main() {
    menu();
    return 0;
}