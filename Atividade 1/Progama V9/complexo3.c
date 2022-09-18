
#include <stdio.h>
#include <math.h>
#include <complex.h>

int main()
{
    float r1,r2,r3;
    complex c1,c2,c3,cvetor[1000];
    int i;

    c2 = 0+0*I;
    for (i = 0; i <=10; i++)
    {
        c1 = i+i*I;
        cvetor[i] = c1;
        printf("(%lf, %lf)\n", creal(cvetor[i]), cimag(cvetor[i]));

        c2 = c2 + cvetor[i];
    }
    printf("A soma = (%lf, %lf)\n", creal(c2), cimag(c2));



    printf("\n\n\n\n\nMultiplixando por 2\n");
    for (i = 0; i <=10; i++)
    {
        c1 = i+i*I;
        cvetor[i] = c1;
        cvetor[i] = 2*cvetor[i];
        printf("(%lf, %lf)\n", creal(cvetor[i]), cimag(cvetor[i]));

    }
    return 0;

}