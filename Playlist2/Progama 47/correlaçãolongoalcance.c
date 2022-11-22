#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define NN 30000
#define RAN() ((double)rand()/(double)(RAND_MAX))

int main(int argc, char const *argv[])
{
    FILE *fil;
    fil = fopen("numeros.dat","w");


    int i,k,j,N;
    double m1,m2,NR,r1,r2,alpha,ir,kr,pi;
    double epsi[NN+1],phi[NN+1];


    N = 10000;
    NR = (double)N;
    pi = 2.*asin(1.);
    alpha = 3.;


    for (i = 1; i <= (N/2); i++)
    {
        phi[i] = 2.*pi*RAN();
    }
    m1=m2=0.;
    for (i = 1; i <= N; i++)
    {
        ir=(double)i;
        epsi[i]=0.;
        for ( k = 1; k <=(N/2) ; k++)
        {
            kr=(double)k;
            r1=pow(kr,alpha*0.5);
            r1=1./r1;
            r2=cos(2.*pi*ir*kr/NR+phi[k]);
            epsi[i]=epsi[i]+r1*r2;
        }
        m1=m1+epsi[i];
        m2=m2+pow(epsi[i],2.);
    }
    m1=m1/NR;
    m2=m2/NR;

    for ( i = 1; i <= N; i++)
    {
        epsi[i]=(epsi[i]-m1)/sqrt(m2-m1*m1);
        fprintf(fil,"%20.8g\n",epsi[i]);
    }
    
    





    return 0;
}
