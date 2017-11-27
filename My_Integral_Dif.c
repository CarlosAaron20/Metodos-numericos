#include "My_Integral_Dif.h"


//Funcion a integrar
double FI(float x){
  double ans = 0.0;
  //ans = 400 * MyPowI(x,5) - 900 * MyPowI(x,4) + 675 * MyPowI(x,3) - 200 * MyPowI(x,2) + 25 * x + 0.2;
  //ans = Expo((-x*x) / 2.0,20) / Raiz_2(2.0 * PI);
ans = x*x;
  return(ans);
}//fin evalua integral

//metodo del trapecio multiple
double TrapecioM(float a, float b, int n ){
  double ans = 0.0, h, sum = 0.0;
  int i;
  h = (b - a) / n;

   for(i = 1;i < n; i++)
    sum += FI(a + i * h);

  ans = (FI(a) + 2.0 * sum + FI(b)) * h / 2.0;
  return(ans);
}//fin trapecio multiple

//Ingrar definidamente un polinomio
double IntegraDefPol(polinomio a, float li, float ls){

     polinomio b = {0};
     double ans;

     b = PolIntegral(a);
     ans = PolEval(b,ls) - PolEval(b,li); //limite inferior menos limite superior

   return(ans);

}//fin integra polinomio y evalualo

//Regla de simpson 1/3 aplicacion multiple
double Simpson3M(float a, float b, int n){
  double ans = 0.0, sp = 0.0, si = 0.0, h;
  int i;

   if(Residuo(n,2.0) != 0.0)
    n++;
   h = (b - a) / n;
    for(i = 1; i < n-1; i+=2)
        si += FI(a + i * h);
    for(i = 2; i < n-2; i+=2)
        sp += FI(b + i * h);

    ans = (FI(a) + 4.0 * si + 2.0 * sp + FI(b)) * h / 3.0;

return(ans);
}
