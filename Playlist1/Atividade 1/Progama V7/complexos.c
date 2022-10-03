#include <stdio.h>
#include <math.h>
#include <complex.h>

int main(int argc, char const *argv[])
{
    double r1,r2,r3,r4;
    double _Complex c1,c2,c3;

/* Definindo um número complexo */
    c1 = 1+1*I;
    r1 = creal(c1);
    r2 = cimag(c1);
    

/* Calculando o conjulgado */
    //c1 = conj(c1);
    r1 = creal(c1);
    r2 = cimag(c1);
    /* printf("%13.8f  %13.8f\n", r1, r2); */


/* Operações com complexos */
    c2 = 2+2*I;
    c3 = c1*c2;


/*Modulo do número complexo*/
    r1 = creal(c3);
    r2 = cimag(c3);

    r4 = cabs(c3);
    printf(" %13.8f\n",r4*r4);

    return 0;
}
