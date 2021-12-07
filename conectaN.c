//
// Created by Usuario on 04/12/2021.
//
#include "conectaN.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>


//--------------------------------------------------------------------------------------
                   //Estructuras sobre las que se basa el juego
struct movimiento{
    int jugador;
    int renglon;                                     //Movimiento: se guarda cordenada de cada ficha y jugador que representa
    int columna;
};

typedef struct movimiento Movimiento;

struct juego{
    Movimiento **jugador1;
    int turno;                                     //Juego: Estructura intermedia que contiene además información útil como "N" y número de movimientos ("Turno")
    int N;
};
//---------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------
                    //Inicializadores de estructuras
Movimiento *crearMovimiento(){
    Movimiento *nuevoMov = malloc(sizeof(Movimiento));
    nuevoMov->jugador = 0;
    nuevoMov->renglon = 0;
    nuevoMov->columna = 0;

    return nuevoMov;
};

typedef struct juego Juego;                         //Regresa una estructura vacía

Juego *nuevoJuego(int N){
    Juego *nuevoJuego = malloc(sizeof(Juego));

    Movimiento **arreglo1 = malloc(1000);
    nuevoJuego->jugador1 = arreglo1;

    nuevoJuego-> turno = 0;
    nuevoJuego->N = N;                          //<--Para crear un juego es necesario indicar el número
                                                //    de fichas que se tienen que conectar para ganar (N)
    return nuevoJuego;
};
//------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------
//                                   .:Funciones:.
void nuevoMovimiento(Juego *juego,int jugador, int renglon, int columna){

    Movimiento *mov = crearMovimiento();
    mov->columna = columna;
    mov->renglon = renglon;
    mov->jugador = jugador;                 //Se crea un movimiento nuevo y se le asignan las coordenadas y el jugador correspondiente

    Movimiento **array = juego->jugador1;
    *((array + juego->turno)) = mov;        //Se obtiene el arreglo de movimientos y se agrega el nuevo ahí

    if(juego->turno >= (juego->N*2) - 2) {  //Si hay una cantidad suficiente de fichas como para que haya un ganador
        ganoColumna(juego, juego->N, mov);
        ganoRenglon(juego, juego->N, mov);          //Preguntamos si gana con alguna de las reglas de conecta N
        ganoDiagonalDerecha(juego, juego->N, mov);
        ganoDiagonalIzquierda(juego, juego->N, mov);
    }

    juego->turno++;

}

//              .:Funciones para evaluar si hay ganador:.
int ganoColumna(Juego *juego, int N, Movimiento *mov){

    int renglon = mov->renglon;
    int columna = mov->columna;
    int minRenglon = 0;
    int maxRenglon = 0;
                                                        //Para saber si hay N fichas del mismo color juntas en una columna
    int b = 1;
    int i;

    if(mov->jugador == 1) {
        Movimiento **array = juego->jugador1;
        while(b == 1) {
            b = 0;                                    //Para ser consistentes en las funciones de ganador se busca el limite superior de la línea ganadora
            i = 0;
            renglon++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon  && (*(array + i))->jugador == 1)
                    b = 1;
                else
                    i++;
            }
        }
        maxRenglon = renglon - 1;
        //int maxRenglon = renglon - 1;

        b = 1;
        renglon = mov->renglon;                     //Después buscamos el limite inferior
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 0;
            renglon--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon && (*(array + i))->jugador == 1)
                    b = 1;
                else
                    i++;
            }
        }
        minRenglon = renglon + 1;
    }else{                                                  //<--- Igual para el segundo jugador
        Movimiento **array2 = juego->jugador1;
        while(b == 1) {
            b = 0;
            i = 0;
            renglon++;
            while (b == 0 && i < juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon && (*(array2 + i))->jugador == 2)
                    b = 1;
                else
                    i++;
            }
        }
        maxRenglon = renglon - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 0;
            renglon--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon && (*(array2 + i))->jugador == 2)
                    b = 1;
                else
                    i++;
            }
        }
        minRenglon = renglon + 1;

    }
    int diferencia = N - 1;
    if((maxRenglon - diferencia) == minRenglon) {       //Si al restar N-1 al límite superior da el inferior o más hay ganador
        printf("Si hay ganador por columna J:%d, R:%d, C:%d\n", mov->jugador, mov->renglon, mov->columna);
        return 1;
    }else {
        printf("No hay ganador por columna J:%d, R:%d, C:%d\n", mov->jugador, mov->renglon, mov->columna);
        return 0;
    }
}
//<-------------------Todas las funciones que buscan ganador funcionan con la misma lógica------------------------------->//
int ganoRenglon(Juego *juego, int N, Movimiento* mov){

    int renglon = mov->renglon;
    int columna = mov->columna;
    int minColumna = 0;
    int maxColumna = 0;

    int b = 1;
    int i;

    if(mov->jugador == 1) {
        Movimiento **array = juego->jugador1;
        while(b == 1) {
            b = 0;
            i = 0;
            columna++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon  && (*(array + i))->jugador == 1)
                    b = 1;
                else
                    i++;
            }
        }
        maxColumna = columna - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 0;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon  && (*(array + i))->jugador == 1)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna + 1;
    }else{
        Movimiento **array2 = juego->jugador1;
        while(b == 1) {
            b = 0;
            i = 0;
            columna++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon  && (*(array2 + i))->jugador == 2)
                    b = 1;
                else
                    i++;
            }
        }
        maxColumna = columna - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 0;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon  && (*(array2 + i))->jugador == 2)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna + 1;
    }
    int diferencia = N-1;
    if((maxColumna - diferencia) >= minColumna) {
        printf("Si hay ganador por Renglon J:%d, R:%d, C:%d\n", mov->jugador, mov->renglon, mov->columna);
        return 1;
    }else {
        printf("No hay ganador por Renglon J:%d, R:%d, C:%d\n", mov->jugador, mov->renglon, mov->columna);
        return 0;
    }
}

int ganoDiagonalDerecha(Juego *juego, int N, Movimiento* mov){

    int renglon = mov->renglon;
    int columna = mov->columna;
    int minColumna = 0;
    int maxColumna = 0;

    int b = 1;
    int i;

    if(mov->jugador == 1) {
        Movimiento **array = juego->jugador1;
        while(b == 1) {
            b = 0;
            i = 0;
            renglon++;
            columna++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon && (*(array + i))->jugador == 1)
                    b = 1;
                else
                    i++;
            }
        }
        maxColumna = columna - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 0;
            renglon--;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon  && (*(array + i))->jugador == 1)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna + 1;
    }else{
        Movimiento **array2 = juego->jugador1;
        while(b == 1) {
            b = 0;
            i = 0;
            renglon++;
            columna++;
            while (b == 0 && i < juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon  && (*(array2 + i))->jugador == 2)
                    b = 1;
                i++;
            }
        }
        maxColumna = columna - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 0;
            renglon--;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon  && (*(array2 + i))->jugador == 2)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna + 1;
    }
    int diferencia = N-1;
    if((maxColumna - diferencia) >= minColumna) {
        printf("Si hay ganador por Diagonal Derecha J:%d, R:%d, C:%d\n", mov->jugador, mov->renglon, mov->columna);
        return 1;
    }else {
        printf("No hay ganador por Diagonal Derecha J:%d, R:%d, C:%d\n", mov->jugador, mov->renglon, mov->columna);
        return 0;
    }
}

int ganoDiagonalIzquierda(Juego *juego, int N, Movimiento* mov){

    int renglon = mov->renglon;
    int columna = mov->columna;
    int minColumna = 0;
    int maxColumna = 0;

    int b = 1;
    int i;

    if(mov->jugador == 1) {
        Movimiento **array = juego->jugador1;
        while(b == 1) {
            b = 0;
            i = 0;
            renglon++;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon  && (*(array + i))->jugador == 1)
                    b = 1;
                else
                    i++;
            }
        }
        maxColumna = columna + 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 0;
            renglon--;
            columna++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon  && (*(array + i))->jugador == 1)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna - 1;
    }else{
        Movimiento **array2 = juego->jugador1;
        while(b == 1) {
            b = 0;
            i = 0;
            renglon++;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon  && (*(array2 + i))->jugador == 2)
                    b = 1;
                else
                    i++;
            }
        }
        maxColumna = columna + 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 0;
            renglon--;
            columna++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon  && (*(array2 + i))->jugador == 2)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna - 1;
    }
    int diferencia = N-1;
    if((minColumna - diferencia) >= maxColumna) {
        printf("Si hay ganador por Diagonal Izquierda J:%d, R:%d, C:%d\n", mov->jugador, mov->renglon, mov->columna);
        return 1;
    }else {
        printf("No hay ganador por Diagonal Izquierda J:%d, R:%d, C:%d\n", mov->jugador, mov->renglon, mov->columna);
        return 0;
    }
}

//--------------------------------------------------------------------------------------------
//      .:Funciones para obtener datos del juego en el main e imprimir el tablero:.

Movimiento **getArray(Juego *juego){
    return juego->jugador1;
}

int getTurno(Juego *juego){
    return juego->turno;
}

int getCol(Movimiento *mov){
    return mov->columna;
}
int getRen(Movimiento *mov){
    return mov->renglon;
}

int getJug(Movimiento *mov){
    return mov->jugador;
}



