#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define ANCHO 50
#define ALTO 10
#define ALTURA_SALTO 5 // Ajusta la distancia para el salto
#define VELOCIDAD_JUEGO 50 // Ajusta este valor para cambiar la velocidad del juego

int gameOver;
int puntaje;
int dinoX, dinoY;
int cactusX, cactusY;

void configuracion() {
    gameOver = 0;
    puntaje = 0;
    dinoX = 5;
    dinoY = ALTO - 1;
    cactusX = ANCHO - 5;
    cactusY = ALTO - 1;
}

void dibujar() {
    system("cls");
    for (int i = 0; i < ALTO; i++) {
        for (int j = 0; j < ANCHO; j++) {
            if (i == dinoY && j == dinoX)
                printf("R");
            else if (i == cactusY && j == cactusX)
                printf("+");
            else if (i == ALTO - 1)
                printf("_");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("Puntaje: %d\n", puntaje);
}

void saltar() {
    if (dinoY >= ALTO - ALTURA_SALTO)
        dinoY -= ALTURA_SALTO;
}

void entrada() {
    if (_kbhit()) {
        char tecla = _getch();
        if (tecla == ' ')
            saltar();
    }
}

void actualizar() {
    if (dinoY < ALTO - 1)
        dinoY++;
    cactusX--;
    if (cactusX <= 0) {
        cactusX = ANCHO - 5;
        puntaje++;
    }
    if ((cactusX == dinoX) && (cactusY == dinoY))
        gameOver = 1;
}

int main() {
    configuracion();
    while (!gameOver) {
        dibujar();
        entrada();
        actualizar();
        Sleep(VELOCIDAD_JUEGO); // Ajusta la velocidad del juego
    }
    printf("\n¡Fin del Juego! Puntaje Final: %d\n", puntaje);
    return 0;
}
