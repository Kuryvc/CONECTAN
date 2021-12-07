# Conecta N

Programa del juego *Conecta 4* con la variante de que puedes modificar el tablero y el número de fichas que debe tener tu línea para considerarse ganadora convirtiendolo así en un *Conecta N*. Que funciona con tablero y fichas variables por conectar, utilizando interfaz gráfica [raylib](https://github.com/raysan5/raylib). El ganador también se expresa en la consola tantas veces se deseé jugar, hasta que se cierre la ventana emergente del juego.


## Requisitos

Para ejecutar el programa es necesario instalar la librería raylib y contar con compilador VisualStudio. 
Contar con Clion facilita mucho ambas tareas. 

## Instrucciones para compilarlo y correrlo

Las dimensiones del tablero y la N deseada por conectar, deben especificarse en el main.c, no hay espacio gráfico para insertar dichos datos. 
Se pueden identificar dichas variables como:
- *#define COL* //Para definir el número de columnas que habrá en el tablero.
- *#define ROW* //Para definir el número de renglones/filas que habrá en el tablero.
- *#define CONECT_N* //Para definir el tamaño de N.

## Imagen del juego funcionando

![image](https://user-images.githubusercontent.com/90404985/145031345-9d1bfd27-5c57-4ad8-bfe9-a7cfd62d95aa.png)


