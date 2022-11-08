#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define RAN()  ((double)rand()/(double)(RAND_MAX))

int main(int argc, char const *argv[])
{
    FILE *fil;
    fil = fopen("newton.dat","w");


    double f1,f2,x1,x2,x3,x4;


    x1=500.;
    x3=1.;


    while (x3>1e-8)
    {
        f1=pow(x1,7.)-1000;
        f2=7.*pow(x1,6.);

        x2=x1-f1/f2;
        x3=fabs(x2-x1);
        x1=x2;
        printf("%s   %20.11g\n","raiz=",x1);
    }
    
    f1=pow(x1,7.)-1000.;
    printf("%s   %20.11g\n","precisão=",f1);

    return 0;
}
