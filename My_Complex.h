#ifndef MY_COMPLEX_H_INCLUDED
#define MY_COMPLEX_H_INCLUDED

#include "My_Math.h"

//estructura para numeros complejos parte real e imaginaria
typedef struct { float real, imag;
               } complejo;

//imprime numero complejo
void PrintCpx(complejo);

//Suma de numeros complejos
complejo SumCpx(complejo, complejo);

//Multiplicacion de 2 numeros complejos
complejo MultCpx(complejo, complejo);

//Divicion de numeros complejos
complejo DivCpx(complejo, complejo);


#endif // MY_COMPLEX_H_INCLUDED
