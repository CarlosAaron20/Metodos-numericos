#ifndef MY_MATRIX_H_INCLUDED
#define MY_MATRIX_H_INCLUDED

#include "My_Math.h"

#define RMAX 10 //renglones maximos
#define CMAX 10

typedef struct { int ren, col;
                 float mtx[RMAX][CMAX];
               } matriz;

//Funcion que lee una matriz
matriz ScanfMtx(void);

//Funcion que imprime una matriz
void PrintMtx(matriz);

//Funcion de ceros
matriz ZerosMtx(int, int);

//Determinante de una matriz
double Determinante(matriz);

//Multiplicación de 2 matrices
matriz MultMtx(matriz, matriz);

//Suma de 2 matrices
matriz SumMtx(matriz, matriz);

//Resta de 2 matrices
matriz RestMtx(matriz, matriz);

//verifica las caracteristicas de una matriz
int VerificaMtx(matriz a, matriz b);

//Regla de cramer
matriz Cramer(matriz, matriz);

//Descompocision de gauss
matriz DesGauss(matriz, matriz);

//Metodo de gauss-jordan
matriz GaussJordan(matriz, matriz);

//Metodo de gauss-jordan con matriz aumentada
matriz Gauss_J_Aumentada(matriz);

//Matriz identidad
matriz EyeMtx(int);

//Matriz transpuesta
matriz TranspuestaMtx(matriz);

//Matriz inversa por crout
matriz InvCroutMtx(matriz);

//inversa por gauss-jordan
matriz InvGaussMtx(matriz);

//verifica jacobi y gauss-seidel

//metodo iterativo para sistema de ecuaciones (jacobi y gauss-seidel)
matriz IteraMtx(matriz, matriz, matriz, int, int);

//verifica jacobi y gauss seidel
int VerificaSistemaIterativo(matriz);

//metodo de jacobi
matriz JacobiMtx(matriz, matriz, matriz, int);

//metodo de gauss seidel
matriz GaussSeidelMtx(matriz, matriz, matriz, int);

//intercambia renglones y columnas general
matriz IntercambioRenCol(matriz,int,int,int); //<-//
                                               //
//intercambia renglones                        //
matriz InterRen(matriz,int,int);  //<-///////////// intercambio ren y col
                                               //
//intercambia columnas                         //
matriz InterCol(matriz,int,int); //<-//////////////





#endif // MY_MATRIX_H_INCLUDED
