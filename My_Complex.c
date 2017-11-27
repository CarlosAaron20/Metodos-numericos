#include "My_Complex.h"

//imprime numero complejo
void PrintCpx(complejo a){

    if(a.imag < 0)
     printf("\n\t%.5f - %.5fi\n", a.real, Abs(a.imag));
    else
      printf("\n\t%.5f + %.5fi\n", a.real, a.imag);

}//fin imprime un numero complejo

//Suma de 2 numeros complejos
complejo SumCpx(complejo a, complejo b){
    complejo c;

    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;

   return(c);

}//fin suma de 2 numeros complejos

//Multiplicacion de 2 numeros complejos
complejo MultCpx(complejo a, complejo b){
    complejo c;

    c.real = (a.real * b.real) + (-1)*(a.imag * b.imag);
    c.imag = (a.real * b.imag) + (a.imag * b.real);

    return(c);
}//fin mmultiplica 2 numeros complejos

//Divicion de numeros complejos
complejo DivCpx(complejo a, complejo b){
    complejo c = b,d,e, ans;

    c.imag = -b.imag; //conjudado del denominador

    d = MultCpx(a,c);//mult del numerador
    e = MultCpx(b,c);//mult denominador que terminda siendo solo la parte real


    ans.real = d.real / e.real;
    ans.imag = d.imag / e.real;

    return(ans);
}//fin divide 2 numeros complejos




