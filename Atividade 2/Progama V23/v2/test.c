#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
   
   FILE*file;
    file = fopen("tabela.dat", "w");

    double r1, r2, max;
    int i;

    srand(time(NULL));
    max = RAND_MAX;

    for (i = 1; i <= 18000; i++)
    {
        r1 = rand()/max;
        r2 = rand()/max;
        fprintf(file,"%10.8f\n",(r1*r2));
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
