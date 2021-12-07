//
// Created by Mi Compu on 07/12/2021.
//

#include "conectaN.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <raylib.h>
#include "raygui.h"

void DibujarTablero(void) {

    DrawRectangleV((Vector2) {100.2f, 150.2f}, (Vector2) {625.2f, 400.2f}, LIGHTGRAY);

    for (int i = 1; i < ROW; i++) {
        DrawLineV((Vector2) {100.2f, 150.2f + ((400.2f / ROW) * i)}, (Vector2) {725.2f, 150.2f + ((400.2f / ROW) * i)}, BLACK);
    }
    for (int i = 1; i < COL; i++) {
        DrawLineV((Vector2) {100.2f + ((625.2f / COL) * i), 150}, (Vector2) {100.2f + ((625.2f / COL) * i), 550.2f}, BLACK);
    }
} //Dibuja rectángulo base y lo divide mediante lineas según las Columnas y Filas
struct FICHA{
    int x;
    int y;
    float radio;
    Color color;
    int color_int;
    int filaValida[COL];

};//Estructura con los elementos de las fichas del tablero

struct TURNO{
    int x;
    int y;
    float radio;
    Color color;
    int color_int;
};//Estructura con los elementos de la ficha que representa el turno de jugador

static struct TURNO turn = {0};
static struct FICHA ficha = {0};

void InitGame(){ //Inicializa los valores de los elementos de ficha y turno
    turn.x = 200;
    turn.y = 90;
    turn.color = BLUE;
    turn.color_int = 2;
    turn.radio = 15;

    for(int i = 0; i<COL;i++){
        ficha.filaValida[i] = 0;
    }
    ficha.x = 0;
    ficha.y = 0;
    ficha.radio = 0;
    ficha.color = RED;
    ficha.color_int = 1;
};//Inicializa los valores de los elementos de ficha y turno

void Update(int j){

    turn.x = 200;
    turn.y = 90;
    turn.color = RED;
    turn.color_int = 1;
    turn.radio = 15;

    ficha.filaValida[j]++;
    ficha.x = (100.2f + ((625.2f / COL)/2.2f) +((625.2f / COL)*j));
    ficha.y = (550.2f - (((400.2f / ROW))/2.2f )-((400.2f / ROW)* (ficha.filaValida[j]-1)));
    if(COL>ROW){
        ficha.radio = (((625.2f / COL)/2.2f));
    }else{
        ficha.radio = ((400.2f / ROW)/2.2f);
    }

    if (ficha.color_int == 1) {
        ficha.color = BLUE;
        turn.color = RED;
        ficha.color_int = 2;
        turn.color_int = 1;
    } else {
        ficha.color = RED;
        turn.color = BLUE;
        ficha.color_int = 1;
        turn.color_int = 2;
    }

};//Actualiza los valores para cada movimiento y ser representados en cada "Frame" de juego

void DrawGame(Juego *prueba){

    int limite = getTurno(prueba);
    Movimiento **arreglo = getArray(prueba);

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("CONECTA N", 50, 35, 30, BLACK);
    DrawText("TURNO DE: ", 50, 80, 20, BLACK);
    DrawText("Haga click en el boton sobre la columna", 300, 35, 17, BLACK);
    DrawText("en que desea colocar su ficha", 300, 50, 17, BLACK);
    //GuiTextBox((Rectangle){400, 200}, "Move",30, );
    Rectangle textBox = {800 / 2.0f - 100, 180, 225, 50};

    DibujarTablero();

    for (int j = 0; j < COL; j++) { //Imprime los botones y obtiene la columna al hacer click
        if (GuiButton((Rectangle) {100.2f + ((625.2f / COL) * j), 110, (625.2f / COL), (400.2f / ROW)}, "-")) {
            Update(j);
            nuevoMovimiento(prueba, ficha.color_int, ficha.filaValida[j], j);
        }
    }

    for (int i = 0; i < limite; ++i) { //obtiene datos del movimiento e imprimie la ficha
        Movimiento *mov = *(arreglo+i);
        int columna = getCol(mov);
        int renglon = getRen(mov);
        int jugador = getJug(mov);
        if(jugador == 1)
            DrawCircle((100.2f + ((625.2f / COL)/2.2f) +((625.2f / COL)*(columna))), (550.2f - (((400.2f / ROW))/2.2f )-((400.2f / ROW)* (renglon - 1))), ficha.radio, RED);
        else
            DrawCircle((100.2f + ((625.2f / COL)/2.2f) +((625.2f / COL)*(columna))), (550.2f - (((400.2f / ROW))/2.2f )-((400.2f / ROW)* (renglon - 1))), ficha.radio, BLUE);

    }

    DrawCircle(turn.x, turn.y, turn.radio, turn.color); //Imprime ficha que representa el turno

    EndDrawing();
}//Dibuja tablero, botones y fichas


