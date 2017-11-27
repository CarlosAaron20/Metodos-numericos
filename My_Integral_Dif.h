#ifndef MY_INTEGRAL_DIF_H_INCLUDED
#define MY_INTEGRAL_DIF_H_INCLUDED

#include "My_Math.h"
#include "My_PolyRoots.h"

//Funcion a integrar
double FI(float);

//metodo del trapecio multiple
double TrapecioM(float, float, int);

//Ingrar definidamente un polinomio
double IntegraDefPol(polinomio,float,float);

//Regla de simpson 1/3 aplicacion multiple
double Simpson3M(float, float, int);



#endif // MY_INTEGRAL_DIF_H_INCLUDED
