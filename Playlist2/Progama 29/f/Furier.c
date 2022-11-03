#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>


#define PI M_PI



int main(int argc, char const *argv[])
{   
    FILE *fil1;
    fil1=fopen("fourierxfreq.dat","w");
    double _Complex cc1,cc2,cc3,cc4,ic;
    double r1,r2,r3,r4;
    double f,t,dt,df,ff,pi;

    pi = M_PI;
    ff=2.5;
    ic =  0.+1*I;
    dt = 0.01;
    df=0.1;
    for ( f= 0; f <= 5; f = f + df)
    {
        cc1 = 0.+0.*I;
        for (t = -200; t<=200; t= t+dt)
        {
            r1 = cos(2.*pi*ff*t);
            cc1=cc1+r1*cexp(2.*pi*f*t*ic)*dt*I;
        }
        fprintf(fil1,"%10.8g  %10.8g\n",f,cabs(cc1));
    }
    








    return 0;
}
