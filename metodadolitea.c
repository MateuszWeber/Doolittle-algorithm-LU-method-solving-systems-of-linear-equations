#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char w='t';
  int n,i,j,k;
  double suma;
  printf("Program rozwiazuje uklady rownan liniowych postaci Ax=y metoda LU.\nRozklad macierzy wspolczynnikow A, na macierze L i U\njest zrealizowany metoda Dolitlea.\n"); 
  system("start http://pl.wikipedia.org/wiki/Metoda_LU");
  printf("\n");
  while(w=='t'){
  printf("Podaj ilosc rownan. ");
  scanf("%d",&n);
  double A[n][n],L[n][n],U[n][n],Y[n],Z[n],X[n];
  
  printf("\nWprowadz macierz wspolczynnikow A.\n");
  for(i=0;i<n;i++){
                   for(j=0;j<n;j++){scanf("%lf",&A[i][j]);}
                   }
                   
 printf("\nWprowadz wektor danych Y.\n");
 for(i=0;i<n;i++){scanf("%lf",&Y[i]);} 
 
 //Wpisywanie zer do macierzy L i U, wype³nianie przek¹tnej macierzy L jedynkami.
 for(i=0;i<n;i++){
                  for(j=0;j<n;j++){
                                   if(i==j){L[i][j]=1;}
                                   else{L[i][j]=0;}
                                   U[i][j]=0;
                                   }
                  }                 
 
 //Obliczanie wartoœci poszczególnych elementów macierzy.
 for(i=0;i<n;i++){
                  //Obliczanie wierszów macierzy U.
                  for(j=i;j<n;j++){
                                   for(k=0,suma=0;k<i;k++){suma=suma+L[i][k]*U[k][j];}
                                   U[i][j]=A[i][j]-suma; 
                                   }
                  if(U[i][i]==0){
                                 printf("Blad! Metoda Dolitla nie dziala gdy wyraz U[i][i] macierzy wynosi 0!\n");
                                 break;
                                 }
                  //Obliczanie kolumn macierzy L.
                  for(j=i+1;j<n;j++){
                                   for(k=0,suma=0;k<i;k++){suma=suma+L[j][k]*U[k][i];}
                                   L[j][i]=(A[j][i]-suma)/U[i][i];
                                   }
                  }
                  
  printf("\nMacierz dolna L:\n");
  for(i=0;i<n;i++){
                   for(j=0;j<n;j++){printf("%.1lf ",L[i][j]);}
                   printf("\n");
                   }
  printf("\nMacierz gorna U:\n");
  for(i=0;i<n;i++){
                   for(j=0;j<n;j++){printf("%.1lf ",U[i][j]);}
                   printf("\n");
                   }
  //Obliczanie wektora "z" z uk³adu równañ Lz=y.
  Z[0]=Y[0];
  for(i=1;i<n;i++){
                   for(j=0,suma=0;j<i;j++){
                                    suma=suma+L[i][j]*Z[j];
                                    }
                   Z[i]=Y[i]-suma;
                   }
  //Obliczanie wektora wyniku x.
  for(i=n-1;i>=0;i--){
                      for(j=i+1,suma=0;j<n;j++){
                                              suma=suma+U[i][j]*X[j];
                                              }
                      X[i]=(Z[i]-suma)/ U[i][i];
                      }
  printf("Wektor wyniku X:\n");
  for(i=0;i<n;i++){printf("%.2lf ",X[i]);}
  printf("\nJeszcze raz? (t - tak)\n");
  w=getch();
  system("cls");
}
  return 0;
}
