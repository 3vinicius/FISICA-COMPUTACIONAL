#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

double ran1(long int *idum);
#define RAN() ((double)rand()/(double)(RAND_MAX))
#define PI M_PI

int main(int argc, char const *argv[])
{
    FILE*fil,*fil2,*fil1;
    char file[100] = "nomes.dat";
    char namefiles[3][100];
    char resultados[100] = "resultados.dat";
    char a[100];
    fil = fopen(file,"r");
    fil2 = fopen(resultados, "w");


    char nomes[200][200];
    int cont,j, i;
    double x,y,tolt,r;
    double dadosx[2000], dadosy[2000];
    cont = 10;
    fprintf(fil2,"%d", cont);

    while (fgets(namefiles,100,fil) != NULL)
    {
        fil1 = fopen(namefiles, "r");
            while (fscanf(fil1, "%lf  %lf", &x, &y) != EOF)
            {
                printf("%f", x);
                j++;
                dadosx[j-1] = x;
                dadosy[j-1] = y;
           
            }
    }
    for (i = 0; i <= j; i++)
    {
        dadosx[i] += dadosx[i]/(float)cont;
        dadosy[i] += dadosy[i]/(float)cont;
        /* fprintf(resultados, "%10.5lf %10.5lf", dadosx[i], dadosy[i]); */
    }
    

    return 0;
}
