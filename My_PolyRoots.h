#ifndef MY_POLYROOTS_H_INCLUDED
#define MY_POLYROOTS_H_INCLUDED

#define GMAX 10

typedef struct { int grado;
                 float pol[GMAX-1];
               } polinomio;

//captura un polinomio
polinomio ScanfPol(void);

//despliega un polinomio
void PrintPol(polinomio);

//funcion que evalua al polinomio
double PolEval(polinomio, double);

//Funcion que deriva un polinomio
polinomio PolDeriv(polinomio);

//Método de Newton Raphson
double NewtonRPol(polinomio, float, int);

polinomio DivisionSint(polinomio, float); //Divicion sintetica

void Birge_Vieta(polinomio); //muestra raices de un polinomio

//Integra un polinomio definidamente
polinomio PolIntegral(polinomio);




#endif // MY_POLYROOTS_H_INCLUDED
