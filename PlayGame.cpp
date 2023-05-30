#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

void playGame();
void worldMario(int&);
void worldDonkeyKong(int&);
void worldPokemon(int&);

int main() {
    playGame();
    return 0;
}

void playGame() {
    int option;
    srand(time(0));
    option = (rand() % 3) + 1;

    while (option!=0){
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

void worldDonkeyKong(int& option) {
    char yesOrNo;
    cout << "¿Su personaje es del mundo de Donkey Kong? ";
    cin >> yesOrNo;

    if (toupper(yesOrNo) == 'S') {
        // Aquí deberías agregar la lógica para el mundo de Donkey Kong si la respuesta es "Sí"
        option=0;
       
    } else if (toupper(yesOrNo) == 'N') {
        option++;  // Incrementa option en 1 si la respuesta es "No"
       
    } else {
        cout << "Opción no válida";
    }
}

void worldMario(int& option) {
    char yesOrNo;
    cout << "¿Su personaje es del mundo de Mario? ";
    cin >> yesOrNo;

    if (toupper(yesOrNo) == 'S') {
        // Aquí deberías agregar la lógica para el mundo de Donkey Kong si la respuesta es "Sí"
        option=0;
     
    } else if (toupper(yesOrNo) == 'N') {
        option++;  // Incrementa option en 1 si la respuesta es "No"
       
    } else {
        cout << "Opción no válida";
    }
}

void worldPokemon(int& option) {
    char yesOrNo;
    cout << "¿Su personaje es del mundo de Pokémon? ";
    cin >> yesOrNo;

    if (toupper(yesOrNo) == 'S') {
        // Aquí deberías agregar la lógica para el mundo de Donkey Kong si la respuesta es "Sí"
        option=0;
      
    } else if (toupper(yesOrNo) == 'N') {
        option=1;  // Incrementa option en 1 si la respuesta es "No"
    
    } else {
        cout << "Opción no válida";
    }
}