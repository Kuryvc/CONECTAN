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
#define COL 20
#define ROW 20
#define CONECT_N 4
//void* color = &RED;
#include "string.h"



#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION

struct turno_circle{
    int x;
    int y;
    float radio;
    Color color;
    int color_int;
};

void initTurno(struct turno_circle *t, Color col){
    t->x = 200;
    t->y = 90;
    t->radio = 15;
    t->color = col;
    t->color_int = 1;
};


void ChangeTurn(Color *C, int *Color_int) {
    if (Color_int == 1) {
        *C = BLUE;
        *Color_int = 2;
    } else {
        *C = RED;
        *Color_int = 1;
    }
};

struct Button{
    int x;
    int y;
    int width;
    int height;
    int cont;
};

void InitButton(struct Button *B, int i){

    B->x = 100.2f +((625.2f /COL)*i);
    B->y = 110;
    B->width = 625.2f /COL;
    B->height = (400.2f / ROW)-10;
};


void DrawBoard(void) {

    DrawRectangleV((Vector2) {100.2f, 150.2f}, (Vector2) {625.2f, 400.2f}, LIGHTGRAY);

    for (int i = 1; i < ROW; i++) {
        DrawLineV((Vector2) {100.2f, 150.2f + ((400.2f / ROW) * i)}, (Vector2) {725.2f, 150.2f + ((400.2f / ROW) * i)}, BLACK);
    }
    for (int i = 1; i < COL; i++) {
        DrawLineV((Vector2) {100.2f + ((625.2f / COL) * i), 150}, (Vector2) {100.2f + ((625.2f / COL) * i), 550.2f}, BLACK);
    }
}
/*

struct TOKEN{
    int x;
    int y;
    float radio;
    Color color;
    int color_int;
    int filaValida[COL];

};

struct TURN{
    int x;
    int y;
    float radio;
    Color color;
    int color_int;
};

static struct TURN turn = {0};
static struct TOKEN token = {0};
//static radio = 0;


void InitGame(){
    turn.x = 200;
    turn.y = 90;
    turn.color = RED;
    turn.color_int = 1;
    turn.radio = 15;

    for(int i = 0; i<COL;i++){
        token.filaValida[i] = 0;
    }
    token.x = 0;
    token.y = 0;
    token.radio = 0;
    token.color = RED;
    token.color_int = 1;
};



void Update(int j){ //FRAME

    token.filaValida[j]++;
    token.x = (100.2f + ((625.2f / COL)/2.2f) +((625.2f / COL)*j));
    token.y = (550.2f - (((400.2f / ROW))/2.2f )-((400.2f / ROW)* (token.filaValida[j]-1)));
    if(COL>ROW){
        token.radio = (((625.2f / COL)/2.2f));
    }else{
        token.radio = ((400.2f / ROW)/2.2f);
    }

    if (token.color_int == 1) {
        token.color = BLUE;
        turn.color = BLUE;
        token.color_int = 2;
        turn.color_int = 2;
    } else {
        token.color = RED;
        turn.color = RED;
        token.color_int = 1;
        turn.color_int = 1;
    }

};

void DrawGame(Juego *prueba){

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("CONECTA N", 50, 35, 30, BLACK);

    //DrawLine(70, 50, 75, 70, BLACK);
    DrawText("TURNO DE: ", 50, 80, 20, BLACK);

    //GuiTextBox((Rectangle){400, 200}, "Move", 30, );
    Rectangle textBox = {800 / 2.0f - 100, 180, 225, 50};


    DrawBoard();

    for (int j = 0; j < COL; j++) {
        if (GuiButton((Rectangle) {100.2f + ((625.2f / COL) * j), 110, (625.2f / COL), (400.2f / ROW) - 10}, "-")) {
            Update(j);
            nuevoMovimiento(prueba, token.color_int, token.filaValida[j], j);
        }
    }

    for(int i = 0; i < (sizeof(token.filaValida)/sizeof(int)); i++) {
        DrawCircle(token.x, token.y, token.radio, token.color);
    }

    DrawCircle(turn.x, turn.y, turn.radio, turn.color);

    EndDrawing();



    //DrawCircle((100.2f + ((625.2f / COL)/2.2f) +((625.2f / COL)*(j))) , (550.2f - (((400.2f / ROW))/2.2f )-((400.2f / ROW)* (filavalida[j]-1))), radio , color);


}


//float radio = (((625.2f / COL)/2.2f)) ;

//DrawCircle((100.2f + ((625.2f / COL)/2.2f)) , (550.2f - (((400.2f / ROW))/2.2f )-((400.2f / ROW)*3)), radio , color);

// Circulo:
//DrawCircle((100.2f + ((625.2f / COL)/2.2f) +((625.2f / COL)*col)) , (550.2f - (((400.2f / ROW))/2.2f )-((400.2f / ROW)*filavalida[col])), radio , color);

*/


int main(void) {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "CONECTA N");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Juego *prueba = nuevoJuego(4);

    //TURNO

    int x = 200;
    int y = 90;
    Color color = RED;
    int color_int = 1;

    int filavalida[COL];
    for(int i = 0; i<COL;i++){
        filavalida[i] = 0;
    }


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        float radio = 0;
        if (COL > ROW) {
            radio = (((625.2f / COL) / 2.2f));
        } else {
            radio = ((400.2f / ROW) / 2.2f);
        }

        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("CONECTA N", 50, 35, 30, BLACK);

        //DrawLine(70, 50, 75, 70, BLACK);
        DrawText("TURNO DE: ", 50, 80, 20, BLACK);

        //GuiTextBox((Rectangle){400, 200}, "Move", 30, );
        Rectangle textBox = {screenWidth / 2.0f - 100, 180, 225, 50};

        DrawBoard();

        for (int j = 0; j < COL; j++) {
            if (GuiButton((Rectangle) {100.2f + ((625.2f / COL) * j), 110, (625.2f / COL), (400.2f / ROW) - 10}, "-")) {
                filavalida[j]++;
                nuevoMovimiento(prueba, color_int, filavalida[j], j);
                DrawCircle((100.2f + ((625.2f / COL) / 2.2f) + ((625.2f / COL) * j)),(550.2f - (((400.2f / ROW)) / 2.2f) - ((400.2f / ROW) * (filavalida[j] - 1))), radio, color);

                if (color_int == 1) {
                    color = BLUE;
                    color_int = 2;
                } else {
                    color = RED;
                    color_int = 1;

                }
            }
        }

        DrawCircle(x, y, radio, color);


        EndDrawing();

        //----------------------------------------------------------------------------------}

        // De-Initialization
        //--------------------------------------------------------------------------------------
             // Close window and OpenGL context
        //--------------------------------------------------------------------------------------

    }
        CloseWindow();

    return 0;
}
