#include "My_Reg_Inter.h"


//Funcion que lee una matriz
matriz ScanTable(void){
  matriz a;
  int r;

  a.col = 2;

  printf("Captura una tabla e la forma x,y ejemplo 2.0,2.3");
  printf("\nCaptura una matriz de maximo %d pares ordenados\n",RMAX);

 do{

      printf("Numero de renglones: ");
      scanf("%d", &a.ren);

   }while(a.ren > RMAX || a.ren <= 0);


   printf("\n\n");
    for(r = 0;r < a.ren ; r++ ){

        printf("\tx%d,y%d = ", r + 1,r + 1);
        scanf("%f , %f", &a.mtx[r][0], &a.mtx[r][1]);
    }

   return (a);

}//fin scanfmtz

//suma de x
matriz SumTablax(matriz t){
 matriz sx = {4,4};
 int n;
 //   n   sx   sx2  sx3
 //   00  01   02   03
 //   sx  sx2  sx3  sx4
 //   10  11   12   13
 //   sx2 sx3  sx4  sx5
 //   20  21   22   23
 //   sx3 sx4  sx5  sx6
 //   30  31   32   33

  sx.mtx[0][0] = t.ren;  //n
   for(n = 0; n < t.ren; n++){
      sx.mtx[0][1] += t.mtx[n][0]; //sx
      sx.mtx[0][2] += MyPowI(t.mtx[n][0],2); //sx2
      sx.mtx[0][3] += MyPowI(t.mtx[n][0],3); //sx3
      sx.mtx[1][3] += MyPowI(t.mtx[n][0],4); //sx4
      sx.mtx[2][3] += MyPowI(t.mtx[n][0],5); //sx5
      sx.mtx[3][3] += MyPowI(t.mtx[n][0],6); //sx6


   }
      sx.mtx[1][0] = sx.mtx[0][1]; //x
      sx.mtx[2][0] = sx.mtx[1][1] = sx.mtx[0][2] ; //x2
      sx.mtx[3][0] = sx.mtx[2][1] = sx.mtx[1][2] = sx.mtx[0][3]; //x3
      sx.mtx[3][1] = sx.mtx[2][2] = sx.mtx[1][3]; //x4
      sx.mtx[3][2] = sx.mtx[2][3]; //x5

 return(sx);

}//fin suma de x

//suma de xy
matriz SumTablaxy(matriz t){
    matriz sxy = {4,1};
    int n;
    //  sy  00
    //  sxy 10
    //  s2y 20
    //  s3y 30

    for(n = 0; n < t.ren; n++){
        sxy.mtx[0][0] += t.mtx[n][1]; //sy
        sxy.mtx[1][0] += t.mtx[n][0] * t.mtx[n][1]; //sxy
        sxy.mtx[2][0] += MyPowI(t.mtx[n][0],2) * t.mtx[n][1]; //sx2y
        sxy.mtx[3][0] += MyPowI(t.mtx[n][0],3) * t.mtx[n][1]; //sx3y
    }

return(sxy);
}//fin suma de xy

//Regresion
matriz Regresion(matriz t, int n){
    matriz a = {0,0},sx,sxy;
    if(n <= 0 || n > 3){
        printf("\n\tNo se puede realizar la regresion min 1 max 3");
    }
    else{
        n++;
        sx = SumTablax(t);
        sxy = SumTablaxy(t);
        sx.ren = sxy.ren = sx.col = n;
PrintMtx(sx);
        a = Cramer(sx,sxy);

    }

    return(a);

}

//regresion lineal
float RegLin(matriz t, float x){
    float ans = 0.0;
    matriz a;
    a = Regresion(t,1);
    printf("\n\tLa regresion lineal es:");
    if(a.mtx[1][0] >= 0.0)
      printf("\n\t y = %f + %f x",a.mtx[0][0], a.mtx[1][0]);
      else
        printf("\n\t y = %f - %f x",a.mtx[0][0], -a.mtx[1][0]);
        ans = a.mtx[0][0] + a.mtx[1][0] * x;
       printf("\n\t La evaluacion de Y(%f) = %f",x, ans );

    return(ans);

}//fin regresion lineal

//Regresion cuadratica
float RegCuad(matriz t,float x){
   float ans = 0.0;
    matriz a;

    a = Regresion(t,2);
    printf("\n\tLa regresion cuadratica es:");
    if(a.mtx[1][0] >= 0.0 && a.mtx[2][0] >= 0.0)
      printf("\n\t y = %f + %f x + %f x^2",a.mtx[0][0], a.mtx[1][0], a.mtx[2][0]);

      else if(a.mtx[1][0] < 0.0 && a.mtx[2][0] >= 0.0)
        printf("\n\t y = %f - %f x + %f x^2",a.mtx[0][0], -a.mtx[1][0], a.mtx[2][0]);

        else if(a.mtx[1][0] >= 0.0 && a.mtx[2][0] < 0.0)
          printf("\n\t y = %f + %f x - %f x^2",a.mtx[0][0], a.mtx[1][0], -a.mtx[2][0]);

          else if(a.mtx[1][0] < 0.0 && a.mtx[2][0] < 0.0)
          printf("\n\t y = %f - %f x - %f x^2",a.mtx[0][0], -a.mtx[1][0], -a.mtx[2][0]);

        ans = a.mtx[0][0] + a.mtx[1][0] * x + a.mtx[2][0],2 * MyPowI(x,2);
       printf("\n\t La evaluacion de Y(%f) = %f",x, ans );

    return(ans);

}//fin regresion cuadratica

//Regresion cubica
float RegCubica(matriz t,float x){
   float ans = 0.0;
    matriz a;

    a = Regresion(t,3);
    PrintMtx(a);
    printf("\n\tLa regresion cubica es:");
    if(a.mtx[1][0] >= 0.0 && a.mtx[2][0] >= 0.0 && a.mtx[3][0] >= 0.0) // + + +
      printf("\n\t y = %f + %f x + %f x^2 + %f x^3",a.mtx[0][0], a.mtx[1][0], a.mtx[2][0], a.mtx[3][0]);

      else if(a.mtx[1][0] >= 0.0 && a.mtx[2][0] >= 0.0 && a.mtx[3][0] < 0.0) // + + -
      printf("\n\t y = %f + %f x + %f x^2 - %f x^3",a.mtx[0][0], a.mtx[1][0], a.mtx[2][0], -a.mtx[3][0]);

       else if(a.mtx[1][0] >= 0.0 && a.mtx[2][0] < 0.0 && a.mtx[3][0] >= 0.0) // + - +
       printf("\n\t y = %f + %f x - %f x^2 + %f x^3",a.mtx[0][0], a.mtx[1][0], -a.mtx[2][0], a.mtx[3][0]);

        else if(a.mtx[1][0] >= 0.0 && a.mtx[2][0] < 0.0 && a.mtx[3][0] < 0.0) // + - -
        printf("\n\t y = %f + %f x - %f x^2 - %f x^3",a.mtx[0][0], a.mtx[1][0], -a.mtx[2][0], -a.mtx[3][0]);

         else if(a.mtx[1][0] < 0.0 && a.mtx[2][0] >= 0.0 && a.mtx[3][0] >= 0.0) // - + +
         printf("\n\t y = %f - %f x + %f x^2 + %f x^3",a.mtx[0][0], -a.mtx[1][0], a.mtx[2][0], a.mtx[3][0]);

          else if(a.mtx[1][0] < 0.0 && a.mtx[2][0] >= 0.0 && a.mtx[3][0] < 0.0) // - + -
          printf("\n\t y = %f - %f x + %f x^2 - %f x^3",a.mtx[0][0], -a.mtx[1][0], a.mtx[2][0], -a.mtx[3][0]);

           else if(a.mtx[1][0] < 0.0 && a.mtx[2][0] < 0.0 && a.mtx[3][0] >= 0.0) // - - +
           printf("\n\t y = %f - %f x - %f x^2 + %f x^3",a.mtx[0][0], -a.mtx[1][0], -a.mtx[2][0], a.mtx[3][0]);

            else if(a.mtx[1][0] < 0.0 && a.mtx[2][0] < 0.0 && a.mtx[3][0] < 0.0) // - - -
            printf("\n\t y = %f - %f x - %f x^2 - %f x^3",a.mtx[0][0], -a.mtx[1][0], -a.mtx[2][0], -a.mtx[3][0]);

        ans = a.mtx[0][0] + a.mtx[1][0] * x + a.mtx[2][0],2 * MyPowI(x,2) + a.mtx[3][0] * MyPowI(x,3);
       printf("\n\t La evaluacion de Y(%f) = %f",x, ans );

    return(ans);

}//fin regresion cubica

//Regresion de potencia
float RegPow(matriz t,float x){
      float ans = 0.0;
    matriz a;
    int signo = 0,n;

    for(n = 0; n < t.ren; n++){
     if(t.mtx[n][0] <= 0 || t.mtx[n][1] <= 0.0){
        signo = 1;
        break;
     }
    else{
        t.mtx[n][0] = LogNat(t.mtx[n][0],20); //Ln(x)
        t.mtx[n][1] = LogNat(t.mtx[n][1],20); //Ln(y)
    }
}//fin for cambia a Ln

   if(signo == 0){
    a = Regresion(t,1);
    a.mtx[0][0] = Expo(a.mtx[0][0],20);//se le saca exponencial para dar el resultado

    printf("\n\tLa regresion de potencia es: ");
      printf("\n\t y = %f * x^%f",a.mtx[0][0], a.mtx[1][0]);
        ans = a.mtx[0][0] + MyPowI(x,a.mtx[1][0]);
       printf("\n\t La evaluacion de y(%.3f) = %f\n",x, ans );
   }

    return(ans);

}//fin regresion de potencia

//Regresion exponencial
float RegExp(matriz t,float x){
   matriz a;
   float ans = 0.0;
   int n;

   for(n = 0; n < t.ren; n++)
    t.mtx[n][1] = LogNat(t.mtx[n][1],30);

   a = Regresion(t,1);
   a.mtx[0][0] = Expo(a.mtx[0][0],30);

    printf("\n\tLa regresion exponencial es: ");
      printf("\n\t y = %f * e^%fx",a.mtx[0][0], a.mtx[1][0]);
        ans = a.mtx[0][0] * Expo(a.mtx[1][0],30);
       printf("\n\t La evaluacion de y(%.3f) = %f\n",x, ans );

       return (ans);

}//fin regresion exponencial

//Regresion logaritmica
float RegLog(matriz t,float x){
    matriz a;
    float ans = 0.0;
    int n;

    for(n = 0; n < t.ren; n++)
        t.mtx[n][0] = LogNat(t.mtx[n][0],20);

    a = Regresion(t,1);

     printf("\n\tLa regresion logaritmica es: ");
      printf("\n\t y = %f * %f*Ln(x)",a.mtx[0][0], a.mtx[1][0]);
        ans = a.mtx[0][0] * a.mtx[1][0] * LogNat(x,20);
       printf("\n\t La evaluacion de y(%.3f) = %f\n",x, ans );

       return (ans);


}//fin regresion logaritmica

//Regresion inversa
float RegInv(matriz t,float x){
    matriz a;
    float ans = 0.0;
    int n;

    for(n = 0; n < t.ren; n++)
        t.mtx[n][0] = (1 / t.mtx[n][0]);

     a = Regresion(t,1);

     printf("\n\tLa regresion inversa es: ");
      printf("\n\t y = %f + %f/x",a.mtx[0][0], a.mtx[1][0]);
        ans = a.mtx[0][0] + a.mtx[1][0] / x;
       printf("\n\t La evaluacion de y(%.3f) = %f\n",x, ans );

       return (ans);



}//Fn regresion inversa

//Interpolacion de Lagrange
float Lagrange(matriz t,float x){
  float ans = 0.0, L;
  int i,j;

    for (i = 0; i < t.ren; i++ ){
        L = 1.0;
      for (j = 0; j < t.ren; j++)
        if(j != i)
          L *= (x - t.mtx[j][0]) / (t.mtx[i][0] - t.mtx[j][0]);
      ans += L * t.mtx[i][1];
    }//fin bucles for

return (ans);

}//fin Lagrange


