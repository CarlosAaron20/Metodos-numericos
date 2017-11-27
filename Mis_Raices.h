#ifndef MIS_RAICES_H_INCLUDED
#define MIS_RAICES_H_INCLUDED

#include <stdio.h>
#include <float.h>

//funcion a estimar raiz
double F(float);

//derivada de la funci�n fprima
double Fp(float);

double FD(float); // clase derivada

void Tabla(float, float, int);

//m�todo de bisecci�n
double Biseccion(float, float, int);

//Imprime la tabla de bisecci�n
void PrintTablaBis(int, double, double);

//m�todo de falsa posici�n
double Falsa_Posicion(float, float, int);

double Newton_Raphson(double,int);

#endif // MIS_RAICES_H_INCLUDED
