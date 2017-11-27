#include "Mis_Raices.h"
#include "My_Math.h"

//Funcion a estimar raiz
double F(float x){

   float ans;

   ans = x * x - 35;

   return (ans);

}


//Funcion prima
double Fp(float x){

   float ans,m=68.5,g=9.81,t=10;

   //ans = (671.985)*( (0.14599*Expo(-0.145985*x,20)/x) - (1-Expo(-0.145985*x,20))/(x*x) ) - 40;

     ans = (g/x)*( (t*Expo(-x*t/m,30)) - (m/x) + (m/x*Expo(-x*t/m,30)) );

   return (ans);

}

//derivada funcion
double FD(float x){

   float ans, h = 0.00390625; //h = 2 ala menos 8
   ans = (F(x + h) - F(x - h)) / (2 * h);

   return (ans);

}

//tabulacion
void Tabla(float min, float max, int n){

  float h;//INCREMENTO
  int i;

  h = (max - min) / n;

  printf("\n\t x\t| f(x)");
  printf("\n\t--------------");

   for(i = 0; i < n; i++){

    printf("\n\t %f \t| %f",min + h * i, F(min + h * i));

   }

}// fin tabla

//metodo de biseccion
double Biseccion(float xi, float xu, int n){
 double ea = 50, es, xr = 0.0, xrant;

 es = Scarb(n);

   if(F(xi) * F(xu) > 0.0)
    printf("No existe raiz en el intervalo");

   else

    do{
        xrant = xr;
      xr = (xi + xu) / 2.0;
      if(F(xi) * F(xr) < 0.0)
        xu = xr;
      if(F(xu) * F(xr) < 0.0)
        xi = xr;

        ea = ErrorA(xr,xrant);

    } while (ea > es);

    return (xr);

}

//Imprime la tabla de bisección
void PrintTablaBis(int n, double xi, double xu){

  int i=1;
  double xr,xr_ant;

  printf("|\t# |\txi\t|\txu\t|\txr\t|\tf(xi)\t|\tf(xu)\t|\tf(xr)\t|\tEa");


   do{

   xr_ant = xr;

   xr = (xi + xu) / 2;



       printf("\n|    %d   |    %.5f    |    %.5f    |    %.5f    |  %.5f    |   %.5f   |    %.5f   |  %.5f",
               i, xi, xu, xr, F(xi), F(xu), F(xr), ErrorA(xr, xr_ant)  );


       if( F(xr) * F(xi) < 0 ) xu = xr;
       else if( F(xr) * F(xu) < 0 ) xi = xr;

 i++;

   }while(i <= n);


}

//método de falsa posición
double Falsa_Posicion(float xi, float xu, int n){

 double ea = 50, es, xr = 0.0, xrant;

 es = Scarb(n);

   if(F(xi) * F(xu) > 0.0)
    printf("No existe raiz en el intervalo");

   else

    do{

        xrant = xr;
        xr = xu-(F(xu)*(xi-xu))/(F(xi)-F(xu));//cambia formula para xr

      if(F(xi) * F(xr) < 0.0)
        xu = xr;
      if(F(xu) * F(xr) < 0.0)
        xi = xr;

        ea = ErrorA(xr,xrant);

    } while (ea > es);

    return (xr);

}

//Metodo de newton raphson
double Newton_Raphson(double x0,int n){

    double ea = 50.0, es, x1;
    es = Scarb(n);

     do{
         x1 = x0 - F(x0) / FD(x0);
         es = ErrorA(x1,x0);


     }while(ea > es);

return(x1);

}

