#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>


#define PI M_PI



int main(int argc, char const *argv[])
{   
    FILE *fil1,*fil2;
    fil1=fopen("fourierxfreq.dat","w");
    fil2=fopen("eqonda.dat", "r");
    double _Complex cc1,cc2,cc3,cc4,ic;
    double r1,r2,r3,r4;
    double f,t,dt,df,ff,pi;
    double x[100000],y[100000];
    int i;

    pi = M_PI;
    ic =  0.+1*I;
    df=0.01;


    for (i = 0; i <= 13000; i++)
    {
        fscanf(fil2, "%g %g", &x[i], &y[i]);
        /* printf("%10.8g %10.8g",x[i],y[i]); */
    }
    


    for ( f= 0; f <= 2; f = f + df)
    {
        cc1 = 0.+0.*I;
        for (i = 1; i<=13000; i++)
        {
            cc1=cc1+y[i]*cexp(f*x[i]*ic);
        }
        fprintf(fil1,"%15.8g        %15.8g\n",f,cabs(cc1));
    }
    








    return 0;
}
