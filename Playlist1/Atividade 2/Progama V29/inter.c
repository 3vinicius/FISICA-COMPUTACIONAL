#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main(int argc, char const *argv[])
{
    double r1,r2,r3;
    double A0,A1,A2;
    double xx,fxx;
    float x[10],fx[10];
    double b0,b1,b2;
    int i;


    FILE*fil,*fil1;

    fil = fopen("dados.dat","w");
    fil1 = fopen("interpolacao.dat","w");

    x[1] = 1;
    x[2] = 2;
    x[3] = 3;

    fx[1] = 0.95;
    fx[2] = 3.4;
    fx[3] = 8.;

    for (i = 1; i <= 3; i++)
    {
        printf("%f\n",x[i]);
        fprintf(fil,"%d %10.5f \n" , i,fx[i]);
    }
    
    b0 = fx[1];
    b1 = (fx[2]-fx[1])/(x[2]-x[1]);
    r1 = (fx[3]-fx[2])/(x[3]-x[2]);
    r2 = (fx[2]-fx[1])/(x[2]-x[1]);
    r3 = (r1-r2)/(x[3]-x[1]);

    b2 = r3;

    A0 = b0 - b1*x[1]+b2*x[1]*x[2];
    A1 = b1 - b2*x[1]-b2*x[2];
    A2 = b2;

    for (xx = 0.5; xx <= 3.5; i += 0.1)
    {
        fxx = A0+A1*xx+A2*xx*xx;
        fprintf(fil1,"%10.8lf   %10.8lf\n", xx, fxx);
    }
    


    return 0;
}

