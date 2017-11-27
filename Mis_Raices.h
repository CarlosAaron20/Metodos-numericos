#ifndef MIS_RAICES_H_INCLUDED
#define MIS_RAICES_H_INCLUDED

#include <stdio.h>
#include <float.h>

//funcion a estimar raiz
double F(float);

//derivada de la función fprima
double Fp(float);

double FD(float); // clase derivada

void Tabla(float, float, int);

//método de bisección
double Biseccion(float, float, int);

//Imprime la tabla de bisección
void PrintTablaBis(int, double, double);

//método de falsa posición
double Falsa_Posicion(float, float, int);

double Newton_Raphson(double,int);

#endif // MIS_RAICES_H_INCLUDED
