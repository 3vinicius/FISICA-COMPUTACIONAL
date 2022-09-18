#include <stdio.h>;
#include <stdlib.h>;
#include <math.h>;

int main(int argc, char const *argv[])
{
    double h;
    double d1;
    double x[300], y[300];
    int i,j;

    FILE*file;
    FILE*file1;

    file = fopen("tabela.dat", "r");
    file1 = fopen("derivada.dat", "w");

    for (i=1; i <= 200 ; i++)
    {
        fscanf(file,"%lf %lf", &x[i], &y[i]);
    
    }

    h = x[3] - x[2];
    for (i = 2; i <= 199; i++)
    {
        d1 = (y[i+1]-y[i-1])/(2*h); 

        fprintf(file1,"%20.8f   %20.8f\n", x[i],d1);
    }
    
    return 0;
}
