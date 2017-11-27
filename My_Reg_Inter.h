#ifndef MY_REG_INTER_H_INCLUDED
#define MY_REG_INTER_H_INCLUDED

#include "My_Matrix.h"

//Funcion que lee una tabla
matriz ScanTable(void);

//suma de x
matriz SumTablax(matriz);

//suma de xy
matriz SumTablaxy(matriz);

//Regresion
matriz Regresion(matriz, int);

//regresion lineal
float RegLin(matriz, float);

//Regresion cuadratica
float RegCuad(matriz,float);

//Regresion cubica
float RegCubica(matriz,float);

//Regresion de potencia
float RegPow(matriz,float);

//Regresion exponencial
float RegExp(matriz,float);

//Regresion logaritmica
float RegLog(matriz,float);

//Regresion inversa
float RegInv(matriz,float);

//Interpolacion de Lagrange
float Lagrange(matriz,float);



#endif // MY_REG_INTER_H_INCLUDED
