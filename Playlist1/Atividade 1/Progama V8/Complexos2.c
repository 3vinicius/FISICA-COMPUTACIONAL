#include <stdio.h>
#include <math.h>
#include <complex.h>

int main(int argc, char const *argv[])
{
    double _Complex c1,c2,c3,cvetor[100];

    c1 = 10+10*I;
    c2 = cexp(c1);
    c3 = csqrt(c1);

    printf("(%lf ,%lf)   (%lf ,%lf)\n", creal(c2), cimag(c2), creal(c3), cimag(c3));

    cvetor[0] = c3;
    cvetor[1] = c2;


    printf("(%lf , %lf)   (%lf , %lf)", creal(cvetor[0]), cimag(cvetor[0]), creal(cvetor[1]), cimag(cvetor[1]));
    return 0;
}
