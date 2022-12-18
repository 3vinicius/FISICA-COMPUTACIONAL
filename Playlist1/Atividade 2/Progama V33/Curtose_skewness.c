#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

double ran1(long int *idum);
#define RAN() ((double)rand()/(double)(RAND_MAX))
#define PI M_PI


int main()
{
    double m1,m2,m3,m4,x[200000],a,b,n;
    int i,N,cont;


    FILE*fil;
    fil = fopen("numerosaleatorioscorre.dat", "r");
   

    cont=i=0.;

    while (fscanf(fil,"%lf", &n) != EOF)
   {
    x[cont] = n;
    cont ++;
    /* printf("%lf\n",x[cont-1]); */
   }

    N = cont-1;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;



    for (i = 1; i <= N; i++)
    {
        m1+=x[i]/(float)N;
    }
   
    for (i = 1; i <= N; i++)
    {
        m2 += pow(x[i]-m1,2)/(float)N;
    }

    for (i = 1; i <= N; i++)
    {
        m3 += pow(x[i]-m1,3)/(float)N;
    }

    for (i = 1; i <= N; i++)
    {
        m4 += pow(x[i]-m1,4)/(float)N;
    }

    a = m3/(pow(m2,3./2.));
    b = m4/(pow(m2,2));

    printf("%10.8lf %10.8lf", a,b);
    return 0;
}
