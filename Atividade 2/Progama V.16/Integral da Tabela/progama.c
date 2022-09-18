#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    FILE*file,*file1;
    file = fopen("tabela.dat", "r");
    file1 = fopen("normalizada.dat" ,  "w");

    double x[600], y[600];
    int i;
    double I, dx,Z;

    for (i = 1; i <= 600; i++)
    {
        fscanf(file, "%lf %lf", &x[i], &y[i]);
        
    }
    

    dx =  x[30] - x[29];
    for (i = 1; i <= 599; i++)
    {
       I += (y[i+1]+y[i])/2*dx;
    }
    

    printf("%f",I);

    /* Para normalizar basta divir todos os dados da tabela pelo resultado da integral */
    /* Lembrando que a normalização da distribuição de probabilidade é igual a 1 */


    for (i = 1; i < 599; i++)
    {
        y[i] = y[i]/I;
        fprintf(file1,"%13.10f  %13.10f\n", x[i], y[i]);
    }
    
    for (i = 1; i <= 599; i++)
    {
       Z += (y[i+1]+y[i])/2*dx;
    }

    printf("\n%f",Z);
    return 0;
}
