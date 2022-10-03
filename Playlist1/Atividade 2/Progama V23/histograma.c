#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    FILE*tabela,*histograma;
    tabela = fopen("tabela.dat", "r");
    histograma = fopen("histograma.dat", "w");

    int i,j,k,cont,Nmax=200000;
    double data[Nmax],r1,r2,x,rmin,rmax,dx;



    cont = 0;
   
   while (fscanf(tabela,"%lf", &x) != EOF)
   {
    cont ++;
    data[cont-1] = x;
  /*   printf("%10.8lf\n", data[cont-1]); */
    
   }
   
   rmin = 100;
   rmax = -100;

   for (i = 1; i <= cont; i++)
   {
        if (data[i]<rmin)
    {
        rmin = data[i];
    }
        if (data[i]>rmax)
    {
        rmax = data[i];
    }
    
   }
   

     dx = (rmax - rmin)/100;


   for (x = dx; x <= rmax - dx; x+=dx);
   {
    r1 = 0;
    for (i = 0; i <= cont; i++)
    {
        if (fabs(data[i]-x) <= (dx*0.5))
        {
            r1 ++;
        }
        /* printf("%lf\n",r1); */
    }

    fprintf(histograma,"%10.8lf  %10.8lf \n", x,r1);
   }
   
    
/* printf("%lf",data[cont-1]); */

    return 0;
}
