#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>


int main(int argc, char const *argv[])
{
    FILE *fil1,*fil2;
    fil1 = fopen("saida.dat","w");
   

    double r1,r2,r3,r4,f,df;
    double _Complex cc1,cc2,cc3,ic;
    double x[300000],y[300000];
    int i,j,N,i10,i20;
    char filname[100] = "niveisk4v2.dat";

    fil2 = fopen(filname,"r");

    ic= 0.+I;

    while ((fscanf(fil2,"%lf %lf %lf %lf\n",&x[i], &y[i],&r1,&r2)!=EOF))
    {
        i++;
    }
    

    i=i-1;
    N=i;
    df = 0.025;

    for ( f = 0.05; f <= 2.0; f+=df)
    {
        cc1=0.+0*I;
        for ( i = 1; i <= N; i++)
        {
            cc1=cc1+y[i]*cexp(-ic*x[i]*f);
        }
        r1=cabs(cc1);
        fprintf(fil1,"%20.8lf   %20.8lf\n",f,r1);
    }
    





 return 0;
}
