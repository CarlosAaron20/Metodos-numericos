#include "My_Math.h"
#include "Mis_Raices.h"

//Valor Absoluto
double Abs(float x){
  return (x<0 ? -x : x);
}

//Residuo de una division
double Residuo(float x, float y){

  float i,r=-1,a=0;

 if(y != 0)
 {
   for(i=y; i<=x; i+=y){
    a++;
   }
  r = x - (a*y);
 }

 return (r);
}

//Potencia de una numero flotante a un entero
double MyPowI(float x, int y){
   float r=1;
   int i;

   if(y > 1 && x != 0){

   r = x;

     for(i=2; i<=y; i++){
       r *= x;
     }

   } else if(y < 0 && x != 0){

     for(i=-1; i>=y; i--){
       r *= x;
   }
    r = 1/r;
   } else if(y == 0 && x == 0) printf("\nerror, cero a la cero");

    else if(x == 0 && y < 0) printf("error, divicion entre cero");

    else if(y == 1) r = x;

    else if(x == 0) r = 0;

       return (r);
}// fin potencia

//raiz cuadrada de un numero por biseccionn
double Raiz_2(double x){
    double ea = 50, es, xr = 0.0, xrant,xi = 0,xu = x;
    int n = 100;

    es = Scarb(n);



   if((xi*xi-x) * (xu*xu-x) > 0.0)
    printf("No existe raiz en el intervalo");

   else

    do{
        xrant = xr;
      xr = (xi + xu) / 2.0;
      if((xi*xi-x) * (xr*xr-x) < 0.0)
        xu = xr;
      if((xu*xu-x) * (xr*xr-x) < 0.0)
        xi = xr;

        ea = ErrorA(xr,xrant);

    } while (ea > es);

    return (xr);

}//fin sacar rraiz cuadrada a un numero

//Factorial de un numero entero
double Factorial(int x){

    float fac = 1;
    int i;

    if (x < 0){
            printf("\n\t Error, no hay factoriales negativos\n\t ");
            fac = 0;
    }
    else if(x > 0)
    for(i = 2; i <= x; i++) fac *= i;

    return (fac);
}//fin factorial

//Error de aproximaion con valor actual y valor anterior
double ErrorA(double vact, double vant){
  double ans;

  if(vact == 0.0)
    ans = Abs(vact - vant);

  else
    if(Abs(vact - vant) < DBL_EPSILON)
     ans = 0.0;

     else
        ans = Abs((vact - vant)/vact*100.0);

   return(ans);

}//Fin error de aproximaci�n

//Calcula el scarberaug para las cifras significativas
double Scarb(int n){

   double ans;

     if(n <= 0){

    printf("\nerror, el numero de cifras significativas tiene que ser mayor a cero; se pondra un cinco");

      n = 5;

     }
     else ans = 0.5 * MyPowI(10,2-n);

     return (ans);

}//fin scarb

double Seno(double x, int n){

 double ans = 0.0, ans_ant, ea = 50.0, es;
 es = Scarb(n);
 n=0;
 x = Residuo(x, 2 * PI); //para ver cuantas vueltas dio y llegar a los imsmo pero mas chico

 do{
   ans_ant = ans;

   ans += MyPowI(x,2*n+1) * MyPowI(-1.0,n) / Factorial(2*n+1);

   n++;

   ea = ErrorA(ans, ans_ant);

   }while(ea > es);

 return (ans);

}//fin seno

double Coseno(double x, int n){

 double ans = 0.0, ans_ant, ea = 50.0, es;
 es = Scarb(n);
 n=0;//cambia a uno
 x = Residuo(x, 2 * PI); //Aplica a las funciones periodicas

 do{
   ans_ant = ans;

   ans += MyPowI(x,2*n) * MyPowI(-1.0,n) / Factorial(2*n);

   n++;

   ea = ErrorA(ans, ans_ant);

 }while(ea > es);

 return (ans);

}//fin coseno

//logaritmo natural de x+1
double LogNat(double x, int n){

 double ans = 0.0, ans_ant, ea = 50.0, es;

if(x <= 0)printf("Error, solo hay logaritmos naturales positivos");

else{

 es = Scarb(n);
 n=0;


 do{

   ans_ant = ans;

   ans += ( (1.0)/((2.0*n)+1.0) ) * ( MyPowI(((MyPowI(x, 2.0)-1.0)/(MyPowI(x, 2.0)+1.0)),(2.0*n)+1.0) );

   n++;

   ea = ErrorA(ans, ans_ant);

   }while(ea > es);

}
 return (ans);

}//fin Ln1

//Exponencial e^x
double Expo(double x, int n){

 double ans = 0.0, ans_ant, ea = 50.0, es;
 es = Scarb(n);
 n=0;//se hace contador

 do{
   ans_ant = ans;

   ans += MyPowI(x,n)  / Factorial(n);

   n++;

   ea = ErrorA(ans, ans_ant);

 }while(ea > es);

 return (ans);

}//fin exponencial

double ArcoSeno(double x,int n){

  double ans = 0.0, ans_ant, ea = 50.0, es;
  int i,num,den;

  if(x < -1 || x > 1)printf("Error, arcoseno solo de -1 a 1");
  else{

 es = Scarb(n);
 n = 0;

 do{

   ans_ant = ans;

   for(i=0; i <= n; i++){//numerador

    if(i == 0) num = 1;

    else if(i == 1) num = 1;

    else if(i > 1) num = num * (i+1);

   }

   for(i=0; i <= n; i++){//denominador

    if(i == 0) den = 1;

    else if(i == 1) den = 2;

    else if(i > 1) den = den * (i+i);

   }

  ans +=  (num)/(den) * (MyPowI(x, 2*n+1))/(2*n+1);
  n++;

  ea = ErrorA(ans, ans_ant);

   }while(ea > es);


  }//fin else

 return (ans);

}

double SenoH(double x, int n){

  double ans = 0.0, ans_ant, ea = 50.0, es;



 es = Scarb(n);
 n = 0;

 do{

   ans_ant = ans;

  ans += (MyPowI(x, 2*n+1))/(Factorial(2*+n+1))  ;

  n++;

  ea = ErrorA(ans, ans_ant);

   }while(ea > es);

 return (ans);

}//fin seno hiperbolico

double CosenoH(double x, int n){

  double ans = 0.0, ans_ant, ea = 50.0, es;

 es = Scarb(n);
 n = 0; // cuando se inicia en cero aparece cero a la cero entonces poner un valor de x cercano a cero

 do{

   ans_ant = ans;

  ans += (1)/(Factorial(2*n)) *(MyPowI(x, 2*n))  ;

  n++;

  ea = ErrorA(ans, ans_ant);

   }while(ea > es);

 return (ans);

}//Fin cosenohipebolico
