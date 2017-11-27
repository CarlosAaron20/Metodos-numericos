#include "My_Math.h"
#include "My_PolyRoots.h"

polinomio ScanfPol(void){

 polinomio p;
 int n;

 printf("\n Captura un polinomio de grado maximo %d",GMAX-1); //menos uno por el arreglo inicia en 0
 printf("\n De la forma a0 + a1 x + a2 x^2 + ...+ an x^n");


 do{

    printf("\n\nIngresa el grado del polinomio: ");
    scanf("%d",&p.grado);

 } while( (p.grado < 0) || (p.grado > GMAX-1) );

  for(n = 0; n <= p.grado ; n++ ){

    printf("\n a[%d] = ", n);
    scanf("%f",&p.pol[n]);

  }

  return (p);
}//fin sacnfpol


//despliega un polinomio
void PrintPol(polinomio p){

   int n;

  printf("\n\n");
   for(n = p.grado; n >= 0; n--){

     if(n == 0){ //cuando es de grado 0


       if(p.pol[n] != 0) {

        if(p.pol[n] < 0) printf(" - %.6f", Abs(p.pol[n]) );

        else printf(" + %.6f",p.pol[n]);

       }
     }
     else if(n == 1){ //cuando es de grado 1

     if(p.pol[n] != 0){

      if(p.pol[n] == 1 || p.pol[n] == -1){

         if(p.pol[n] < 0) printf(" - X", Abs(p.pol[n]) );

         else printf(" + X",p.pol[n]);
      }
      else{

        if(p.pol[n] < 0) printf(" - %.6f X", Abs(p.pol[n]) );

        else printf(" + %.6f X",p.pol[n]);

      }
     }

     }
     else {

   if(p.pol[n] != 0){

      if( (p.pol[n] == 1) || (p.pol[n] == -1)) {

         if(p.pol[n] < 0) printf(" - X^%d", n );

        else printf(" + X^%d", n );

      }

       else{

        if(p.pol[n] < 0) printf(" - %.6f X^%d", Abs(p.pol[n]), n );

        else printf(" + %.6f X^%d",p.pol[n], n );

       }
   }

    }


   }//fin ciclo for

   printf("\n");

}//fin printpol

//funcion que evalua polinomio
double PolEval(polinomio a, double x){

    float ans = 0.0;
    int n;

     for(n = a.grado; n >= 0; n--){

        ans = ans * x + a.pol[n];

     }//fin for

     return (ans);

}// fin evalua polinomio

polinomio PolDeriv(polinomio a){

  polinomio b = {0};
  int n;

  if(a.grado >= 1 ){
        b.grado = a.grado - 1;
  for (n = 0; n <= b.grado ; n++){

    b.pol[n] = a.pol[n+1] * (n+1);

  }//fin for

  }

  return (b);

}// fin derivada

//Método de Newton Raphson
double NewtonRPol(polinomio f, float xi, int n){

  int i=0; //contador

  double x1, ea = 50.0, es;
   polinomio fd;
   es = Scarb(n);
   fd = PolDeriv(f);

    do{

        x1 = xi - (PolEval(f,xi) / PolEval(fd,xi));
        ea = ErrorA(x1,xi);
        xi = x1;

      } while(ea > es);

    return (x1);

}

//division sintetica de polinomios
polinomio DivisionSint(polinomio a, float x){ //Divicion sintetica

  polinomio b;
  int i;

  b.grado = a.grado - 1;

  b.pol[b.grado] = a.pol[a.grado];

   for(i = b.grado-1; i >= 0; i--){
    b.pol[i] = a.pol[i + 1] + b.pol[i + 1] * x; //formula cuaderno
   }

   return (b);

}//fon divicion sontetica

//Metodo de Birge Vieta
void Birge_Vieta(polinomio a){

   double x;

    printf("\nTu polinomio de grado %d es: ",a.grado);

         PrintPol(a);

   do{

    x = NewtonRPol(a,-1,6);

    a = DivisionSint(a,x);

    printf("\nEl resultado de la divicion sintetica entre el polinomio de grado %d y la raiz es: \n",a.grado+1);

    PrintPol(a);

    printf("\nY su raiz es: %.6f\n", x);


   }while( a.grado > 0 );

}// fin birge-Vieta

//Integra un polinomio definidamente
polinomio PolIntegral(polinomio a){

    polinomio b = {a.grado + 1};
    int i;

     for(i = a.grado; i >= 0; i--)
        b.pol[i+1] = (a.pol[i]) / (i + 1);

  return(b);

}//fin integra polinomio
