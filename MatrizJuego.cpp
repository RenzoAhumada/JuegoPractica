#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int fillCharacters(int v[10][10]);
int viewCharacter(int v[10][10]);

int main() {
    srand(time(NULL));
    int characters[10][10];
    fillCharacters(characters);
}

int fillCharacters(int v[10][10]) {
    int files = 10; // Número de filas
    int columns = 10; // Número de columnas
    
    for (int i = 0; i < files; i++) {
        for (int j = 0; j < columns; j++) {
            v[i][j] = rand() % 2;
        }
    }
    
    viewCharacter(v);
    return 0;
}

int viewCharacter(int v[10][10]) {
    int files = 10; // Número de filas
    int columns = 10; // Número de columnas
    
    for (int i = 0; i < files; i++) {
        for (int j = 0; j < columns; j++) {
            cout << v[i][j];
        }
    }
    
    return 0;
}

