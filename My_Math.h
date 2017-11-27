#ifndef MY_MATH_H_INCLUDED
#define MY_MATH_H_INCLUDED

#include <stdio.h>
#include <float.h>

#define PI 3.141592654

double Abs(float);//Valor Absoluto

double Residuo(float, float);//Residuo de una divicion

double MyPowI(float, int);//potencia

//raiz cuadrada de un numero por biseccionn
double Raiz_2(double);

double Factorial(int);//Factorial de un numero entero

double ErrorA(double, double);

double Scarb(int);

double Seno(double, int); //Seno de un �ngulo

double Coseno(double, int);

double LogNat(double, int);//Logaritmo natural de x+1, -1 < x <= 1

double Expo(double, int);

double Arcoseno(double,int);

double SenoH(double, int);

double CosenoH(double, int);


#endif // MY_MATH_H_INCLUDED
