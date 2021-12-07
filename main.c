/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "conectaN.h"

#include "raylib.h"
#define COL 45 //Numero de Columnas del tablero
#define ROW 20 //Numero de filas del arreglo
#define CONECT_N 6

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION


int main(void) {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "CONECTA N");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Juego *prueba = nuevoJuego(CONECT_N);
    InitGame();

    // Ciclo principal de main
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        DrawGame(prueba);
    }


    CloseWindow();

    return 0;
}
