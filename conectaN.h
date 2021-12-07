//
// Created by Mi Compu on 07/12/2021.
//

#ifndef CONECTA4A_CONECTAN_H
#define CONECTA4A_CONECTAN_H


typedef struct movimiento Movimiento;
typedef struct juego Juego;

Juego *nuevoJuego(int N);

void nuevoMovimiento(Juego *juego, int jugador, int renglon, int columna);

int ganoColumna(Juego* juego, int N, Movimiento* mov);

int ganoRenglon(Juego* juego, int N, Movimiento* mov);

int ganoDiagonalDerecha(Juego* juego, int N, Movimiento* mov);

int ganoDiagonalIzquierda(Juego* juego, int N, Movimiento* mov);

void printArreglos(Juego * juego);

void printArreglos2(Juego * juego);


#endif //CONECTA4A_CONECTAN_H
