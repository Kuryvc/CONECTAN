//
// Created by Mi Compu on 07/12/2021.
//

#include "conectaN.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>



struct movimiento{
    int jugador;
    int renglon;
    int columna;
};

typedef struct movimiento Movimiento;

struct juego{
    //Movimiento **jugador2;
    Movimiento **jugador1;

    int turno;
    int N;
    //Queue *cola;
};

Movimiento *crearMovimiento(){
    Movimiento *nuevoMov = malloc(sizeof(Movimiento));
    nuevoMov->jugador = 0;
    nuevoMov->renglon = 0;
    nuevoMov->columna = 0;

    return nuevoMov;
};

typedef struct juego Juego;

Juego *nuevoJuego(int N){
    Juego *nuevoJuego = malloc(sizeof(Juego));

    /*Movimiento **arreglo2 = malloc(1000);
    nuevoJuego->jugador2 = arreglo2;*/

    Movimiento **arreglo1 = malloc(1000);
    nuevoJuego->jugador1 = arreglo1;

    nuevoJuego-> turno = 0;
    nuevoJuego->N = N;
    //nuevoJuego->cola = queue_create();

    return nuevoJuego;
};

void nuevoMovimiento(Juego *juego,int jugador, int renglon, int columna){

    Movimiento *mov = crearMovimiento();
    mov->columna = columna;
    mov->renglon = renglon;
    mov->jugador = jugador;

    Movimiento **array = juego->jugador1;
    *((array + juego->turno)) = mov;

    if(juego->turno >= (juego->N*2) - 2) {
        ganoColumna(juego, juego->N, mov);
        ganoRenglon(juego, juego->N, mov);
        ganoDiagonalDerecha(juego, juego->N, mov);
        ganoDiagonalIzquierda(juego, juego->N, mov);
    }
    if(jugador == 1){
        /*
        //*(juego->jugador1) = realloc(*(juego->jugador1), (juego->N + 5) * sizeof(Movimiento));
        Movimiento **array = juego->jugador1;
        *(array + juego->turno) = mov;
        //queue_offer(juego->cola,mov);
        if(juego->turno >= juego->N - 2){
            //ganoColumna(juego, juego->N, mov);
            //ganoRenglon(juego, juego->N, mov);
            //ganoDiagonalDerecha(juego, juego->N, mov);
            //ganoDiagonalIzquierda(juego, juego->N, mov);
        }*/
    }
    if(jugador == 2){
        /*Movimiento **array2 = juego->jugador2;
        *(array2 + juego->turno) = mov;
        //queue_offer(juego->cola,mov);
        if(((juego->turno)) >= juego->N - 2){
            //ganoColumna(juego, juego->N, mov);
            //ganoRenglon(juego, juego->N, mov);
            //ganoDiagonalDerecha(juego, juego->N, mov);
            //ganoDiagonalIzquierda(juego, juego->N, mov);
        }*/
    }
    juego->turno++;


}

int ganoColumna(Juego *juego, int N, Movimiento *mov){

    int renglon = mov->renglon;
    int columna = mov->columna;
    int minRenglon = 0;
    int maxRenglon = 0;

    int b = 1;
    int i;

    if(mov->jugador == 1) {
        Movimiento **array = juego->jugador1;
        while(b == 1) {
            b = 0;
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
        renglon = mov->renglon;
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
        //int minRenglon = renglon + 1;
    }else{
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
        //int maxRenglon = renglon - 1;

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
        //int minRenglon = renglon + 1;
    }
    int diferencia = N - 1;
    if((maxRenglon - diferencia) == minRenglon) {
        printf("Si hay ganador por columna J:%d, R:%d, C:%d\n", mov->jugador, mov->renglon, mov->columna);
        return 1;
    }else {
        printf("No hay ganador por columna J:%d, R:%d, C:%d\n", mov->jugador, mov->renglon, mov->columna);
        return 0;
    }
}

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
        //int maxRenglon = renglon - 1;

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
        //int minRenglon = renglon + 1;
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
        //int maxRenglon = renglon - 1;

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
        //int minRenglon = renglon + 1;
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
        //int maxRenglon = renglon - 1;

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
        //int minRenglon = renglon + 1;
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
        //int maxRenglon = renglon - 1;

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
        //int minRenglon = renglon + 1;
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
        //int maxRenglon = renglon - 1;

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
        //int minRenglon = renglon + 1;
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
        //int maxRenglon = renglon - 1;

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
        //int minRenglon = renglon + 1;
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

void printArreglos(Juego * juego){
    int i = 0;
    Movimiento **array = juego->jugador1;

    while (i<juego->turno){

        Movimiento *mov = *(array+i);
        printf("Movimiento %d Jugador %d: R:%d C:%d \n",i, mov->jugador, mov->renglon, mov->columna);
        printf("\n");
        i++;
    }
}

/*void printArreglos2(Juego * juego){
    int i = 0;
    Movimiento **array = juego->jugador2;
    while (i<juego->turno){
        Movimiento *mov = *(array+(sizeof(Movimiento)*i));
        printf("Movimiento %d Jugador2: R:%d C:%d \n",i,mov->renglon, mov->columna);
        printf("\n");
        i++;
    }
}
*/
/*Queue *regresaCola(Juego *juego){
    return juego->cola;
}*/

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
