#include <stdio.h> ;
#include <math.h> ;
#include <stdlib.h> ;

int main()
{
    /* Definições */
    double fx,f2h,fh,h,x,d1,d2,d3;
    x = 2.;
    h = 0.0005;
    fx = log(x);
    

    /* Calculando "derivada futura" */
    f2h = log(x+2*h);
    fh = log(x+h);
    d1 = (-3*fx+4*fh-f2h)/(2.*h);


    /* Calculando "derivada Passada" */
    f2h = log(x-2*h);
    fh = log(x-h);
    d2 = (3*fx+f2h-4*fh)/(2.*h);


    /* Calculando derivada na mão*/
    d3 = 1./x;


    /* Resultados: */
    printf("d1 = %13.8f d2 = %13.8f d3 = %13.8f ", d1,d2,d3);
    printf("\nd1 - d3 =%13.8f \nd1 - d2 =%13.8f", fabs(d1-d3), fabs(d3 - d2));
    return 0;
}
