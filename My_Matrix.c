#include "My_Matrix.h"

//Funcion que lee una matriz
matriz ScanfMtx(void){
  matriz a;
  int r, c;


  printf("\nCaptura una matriz de maximo %d x %d\n",RMAX, CMAX);

 do{

      printf("Numero de renglones: ");
      scanf("%d", &a.ren);

   }while(a.ren > RMAX || a.ren <= 0);

   do{

      printf("Numero de columas: ");
      scanf("%d", &a.col);

   }while(a.col> CMAX || a.col <= 0);

   printf("\n\n");
    for(r = 0;r < a.ren ; r++ )
    for(c = 0;c < a.col ; c++ ){

        printf("a[%d][%d] = ", r + 1, c + 1);
        scanf("%f", &a.mtx[r][c]);
    }

   return (a);

}//fin scanfmtz

//Funcion que imprime una matriz
void PrintMtx(matriz a){

  int r, c;

  if(a.col> CMAX || a.col <= 0)
    a.col = 0;
  if(a.ren>RMAX || a.ren <= 0)
    a.ren = 0;

    printf("\n");

   for(r = 0; r < a.ren ; r++){
    for(c = 0; c < a.col ; c++)
     printf("\t%.5f ", a.mtx[r][c] );
     printf("\n");
   }


}//fin imprime matriz

//Funcion de ceros
matriz ZerosMtx(int r, int c){

 matriz a = {r,c};

 if(a.col> CMAX || a.col <= 0)
    a.col = 0;
  if(a.ren>RMAX || a.ren <= 0)
    a.ren = 0;

 return (a);

}//fin zeros

//Determinante de una matriz por cofactores
double Determinante(matriz a){

  matriz maux;
  double d = 0.0;
  int r, k, c, n;

  if(a.ren != a.col)
    printf("\nError, La matriz debe ser cuadrada,");

  else{
    if(a.ren == 1)
    d = a.mtx[0][0];

    else{

        for(n = 0; n < a.ren; n++){

            maux = ZerosMtx(a.ren - 1, a.col - 1);
            r = 0;
            for (k = 0;k < a.ren; k++)
                if(n != k){
                 for (c = 1;c < a.col ;c++)
                  maux.mtx[r][c-1] = a.mtx[k][c];
                r++;
                }

            d += a.mtx[n][0] * MyPowI(-1, n) * Determinante(maux);
///printf("\nd = %f",d);

        }//fin for

    }//fin else == 1


  }//fi if de a.ren

  return (d);

}//fin determinante

//multiplicacion de matrices
matriz MultMtx(matriz a, matriz b){

matriz c;

int i,j,k,escalar;

 if(b.ren > 1 && b.col > 1 ){

 c.ren = a.ren; c.col = b.col;

   for(i=0; i<a.ren ; i++ ){
    for(j=0; j<b.col ; j++ ){c.mtx[i][j]=0;
     for(k=0; k<a.col ; k++ )
   c.mtx[i][j] =  c.mtx[i][j] + a.mtx[i][k] * b.mtx[k][j];
                            }
   }
 }//fin if
 else if(b.ren == 1 && b.col == 1){

 c.ren = a.ren; c.col = a.col;

  escalar = b.mtx[0][0];

   for(i=0; i<a.ren ; i++ )
    for(j=0; j<a.col ; j++ )
      c.mtx[i][j] = a.mtx[i][j] * (escalar);

 }//fin else escalar

 return (c);

}//fin multiplicación de 2 matrices

//Suma de 2 matrices
matriz SumMtx(matriz a, matriz b){
    matriz c;
    int i,j;

    c.ren = a.ren;
    c.col = a.col;


    if(a.ren != b.ren || a.col != b.col){

      printf("\n\nError, matrices deben tener el mismo numero de renglones y columnas");
      c = ZerosMtx(1,1);
    }
    else{

    for(i=0; i<a.ren ; i++ ){
        for(j=0; j<a.col ; j++ ){
            c.mtx[i][j] = a.mtx[i][j] + b.mtx[i][j];
        }
    }

    }

    return (c);
}//fin suma mtx

//Resta de 2 matrices
matriz RestMtx(matriz a, matriz b){
    matriz c;
    int i,j;

    if(a.ren != b.ren || a.col != b.col){

      printf("\n\nError, matrices deben tener el mismo numero de renglones y columnas");
      c = ZerosMtx(1,1);
    }
    else{

    for(i=0; i<a.ren ; i++ ){
        for(j=0; j<a.col ; j++ ){
            c.mtx[i][j] = a.mtx[i][j] - b.mtx[i][j];
        }
    }

    }

    return (c);
}//fin Resta mtx

//verifica si la matriz cumple con las condiciones
int VerificaMtx(matriz a, matriz b){
  int ans = 0;

   if(a.ren != a.col){
     printf("\n\t La matriz A no es cuadrada");
     ans = 1;
   }
   if(a.ren != b.ren){
    printf("\n\t La matriz A y B tiene n numero distinto de renglones");
    ans = 2;
   }
   if(1 - (b.col == 1 || b.col == a.col)){
      printf("\n\t Las columnas de B deben ser 1 o de la misma dimension de A");
    ans = 3;

   }
   if(Determinante(a) == 0.0){
     printf("\n\tMatriz singular");
    ans = 4;

   }

return (ans);
}

//regal de cramer
matriz Cramer(matriz a, matriz b){
  matriz x = {1,1}, maux;
  int r,c;
  float da;
   if(VerificaMtx(a,b) != 0)
    printf("\n\tNo se puede resolver por regla de cramer");
   else{
     da = Determinante(a);
     x = ZerosMtx(b.ren,1);
     for(c = 0; c < a.col; c++){
        maux = a;
        for(r = 0; r < a.ren; r++)
            maux.mtx[r][c] = b.mtx[r][0];
        x.mtx[c][0] = Determinante(maux) / da;
     }


   }

return(x);
}//fin regla cramer

//descompocicion de gauss normal
matriz DesGauss(matriz a, matriz b){
 int k,r,c,i;

  if(VerificaMtx(a,b) != 0){
    printf("\n\tNo se puede resolver por gauss");
    b = ZerosMtx(1,1);
  }
  else{
    for(k = 0; k < a.ren - 1; k++)
     for(r = k + 1; r < a.ren; r++){
       b.mtx[r][0] -= a.mtx[r][k] * b.mtx[k][0] / a.mtx[k][k];
        for(c = a.col - 1; c >= 0; c--)
         a.mtx[r][c] -= a.mtx[r][k] * a.mtx[k][c] / a.mtx[k][k];
    }
  for(i = a.ren - 1; i >= 0; i--){
     for(k = i + 1; k < a.ren; k++)
        b.mtx[i][0] -= a.mtx[i][k] * b.mtx[k][0];
    b.mtx[i][0] /= a.mtx[i][i];

  }

  }
 return (b);
}//fin descompicicion de gauss

//metodo exacto de gauss-jordan
matriz GaussJordan(matriz a, matriz b){
  int k,r,c;

  if(VerificaMtx(a,b) != 0){
    printf("\n\tNo se puede resolver por Gauss-Jordan");
    b = ZerosMtx(1,1);
  }
  else{
    for(k = 0; k < a.ren; k++){
      for(c = 0; c < b.col; c++)
        b.mtx[k][c] /= a.mtx[k][k];
      for(c = a.col - 1; c >= k; c--)
        a.mtx[k][c] /= a.mtx[k][k];
      for(r = 0; r > a.ren; r++)
      if(r != k){
        for(c = 0; c < b.col; c++)
          b.mtx[r][c] -= a.mtx[r][k] * b.mtx[k][c];
          for(c = a.col; c >= k; c--)
            a.mtx[r][c] -= a.mtx[r][k] * a.mtx[k][c];
      }//fin del if
  }//fin del for k
}//Fin if else

 return(b);
}//fin gauss jordan

///Metodo de gauss-jordan con matriz aumentada
matriz Gauss_J_Aumentada(matriz a){

  int r,r2,c1,c2,g;

  for(r = 0; r < a.ren; r++){
g = a.mtx[r][r];
    for(c1 = 0; c1 < a.col; c1++){

     printf("%.2f / %.2f",a.mtx[r][c1], a.mtx[r][r]);
       a.mtx[r][c1] /= g;

    }
   for(r2 = 0; r2 < (a.ren); r2++){
    if(r != r2){
    for(c2 = r; c2 < a.col; c2++){

        a.mtx[r2][c2] -= a.mtx[r][c2] * a.mtx[r2][r];

    }
    }//fin if
   }
PrintMtx(a);
  }
  return(a);
}//fin guass-J matriz aumentada

//Matriz identidad
matriz EyeMtx(int n){
  matriz a = {n,n};
 if(a.col> CMAX || a.col <= 0){
    a.col = 0;
    a.ren = 0;
 }
 for(n = 0; n < a.ren; n++)
    a.mtx[n][n] = 1.0;
 return (a);

}//fin matriz odentidad

//Matriz transpuesta
matriz TranspuestaMtx(matriz a){

  matriz c;
  int i,j;

   c.ren = a.ren;
   c.col = a.col;

   for(i=0; i<a.ren; i++)
    for(j=0; j<a.col; j++)
     c.mtx[i][j] = a.mtx[j][i];


  return (c);

}//fin matriz transpuesta

//Matriz inversa por crout
matriz InvCroutMtx(matriz a){

  matriz b,c,aux,aux2;
  int i,j,k;

   b.ren = a.col;
   b.col = 1;

   c.ren = a.ren;
   c.col = a.col;

   aux2.ren = a.ren;
   aux2.col = a.col;

   aux = EyeMtx(a.ren);

   for(i=0; i<a.col ;i++ ){
     for(j=0; j<a.ren ; j++ ){

       b.mtx[j][0] = aux.mtx[i][j];

     }
        c = Cramer(a,b);

        for(k=0; k<a.ren; k++)
          aux2.mtx[k][i] = c.mtx[k][0];
   }

  return(aux2);

}//fin matriz inversa

//inversa por gauss-jordan
matriz InvGaussMtx(matriz a){
  matriz ide, ans;
  ide = EyeMtx(a.ren);

   if(VerificaMtx(a,ide) != 0){
    printf("\n\tNo se puede obtener la inversa");
 ans = ZerosMtx(1,1);
  }
 else
    ans = GaussJordan(a,ide);

 return(ans);

}

//verifica jacobi y gauss seidel
int VerificaSistemaIterativo(matriz a){
  int flag=0,acu,i,j;

    for(i = 0; i <= a.ren - 1; i++){
    acu=0;
      for(j = 0; j <= a.col - 1; j++){

      if(i != j)
        acu += Abs(a.mtx[i][j]);

      }
    if(acu > a.mtx[i][i]){
        printf("\nError, La sumatoria absoluta del renglon %d es mayor que x%d\n",i+1,i+1);
        flag = 1;
    }

    }//fin for

  return(flag);

}

//metodo iterativo para sistema de ecuaciones (jacobi y gauss seidel)
matriz IteraMtx(matriz a, matriz b, matriz x0, int n, int flag){
 matriz x1;
 float es, ea = 50.0;
 int i,j,k;

 es = Scarb(n);
 if(VerificaMtx(a,b) != 0 || VerificaMtx(a,x0) != 0 || VerificaSistemaIterativo(a) != 0){
    printf("\n\tNo se puede resolver");
 x1 = ZerosMtx(1,1);
  }
else{
     while(ea > es){
        x1 = b;
        for(i = 0; i < a.ren; i++){
            for(k = 0; k <= i-1; k++)
             if(flag == 0)
               x1.mtx[i][0] -= a.mtx[i][k] * x0.mtx[k][0];//jacobi
            else
               x1.mtx[i][0] -= a.mtx[i][k] * x1.mtx[k][0]; //gauss seidel
            for (j = i+1; j < a.ren ; j++)
               x1.mtx[i][0] -= a.mtx[i][j] * x0.mtx[j][0];
            x1.mtx[i][0] /= a.mtx[i][i];
        }//fin for
        ea = ErrorA(x1.mtx[0][0],x0.mtx[0][0]);
        x0 = x1;
     }//fin while
}

return(x1);
}//fin itera matriz

//metodo de jacobi
matriz JacobiMtx(matriz a, matriz b, matriz x0, int n){
  return(IteraMtx(a,b,x0,n,0));
}

//metodo de gauss seidel
matriz GaussSeidelMtx(matriz a, matriz b, matriz x0, int n){
   return(IteraMtx(a,b,x0,n,1));
}

//intercambia renglones y columnas general
matriz IntercambioRenCol(matriz a,int rc1,int rc2, int flag){
  matriz aux,ans;

  if( (rc1 > a.ren || rc1 <= 0 ) || (rc2 > a.col || rc2 <= 0) ){
    printf("\n\tError, No concuerdan los renglones o columnas ingresados para intercambiarlos\n");
    ans = ZerosMtx(1,1); //regresa una matriz cero por que no conucerdan los renglones o columnas
  }
  else{
  ans.ren = a.ren;
  ans.col = a.col;
  ans = EyeMtx(a.ren);


  //if( (r1 <= a.ren))

  ans.mtx[rc1-1][rc1-1] = 0;
  ans.mtx[rc1-1][rc2-1] = 1;

  ans.mtx[rc2-1][rc2-1] = 0;
  ans.mtx[rc2-1][rc1-1] = 1;

    if(flag == 0){
      ans = MultMtx(ans,a); //intercambia renglones
      printf("\n\tSe intercambiaran los renglones %d y %d\n",rc1,rc2);
    }
      else if (flag == 1){
        ans = MultMtx(a,ans); //intercambia columnas
        printf("\n\tSe intercambiaran las columnas %d y %d\n",rc1,rc2);
      }

        else
            printf("Error, bandera solo puede ser cero (Ren) o uno (col)");

  }
   return(ans);

}//Fin intercambia renglones y columnas

//intercambia renglones
matriz InterRen(matriz a,int rc1,int rc2){
  return(IntercambioRenCol(a,rc1,rc2,0));
}

//intercambia columnas
matriz InterCol(matriz a,int rc1,int rc2){
  return(IntercambioRenCol(a,rc1,rc2,1));
}







