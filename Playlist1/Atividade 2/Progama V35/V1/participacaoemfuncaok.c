#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

double ran1(long int *idum);
#define RAN() ((double)rand()/(double)(RAND_MAX))
#define PI M_PI

int main(int argc, char const *argv[])
{
    FILE*fil,*fil1,*fil2;
    char file[100] = "nomes.dat";
    char namefiles[100];
    char resultados[100] = "resultados.dat";
    fil = fopen(file,"r");
    fil2 = fopen64(resultados, "w");

    char a;
    int cont,j, i;
    double x,y,tolt,r;
    double dadosx[2000], dadosy[2000];


    while (fscanf(fil, "%s", &a) != EOF)
    {
        printf("%c", a[2][1]);
        cont++;
        namefiles[cont-1] = a;
        printf("%c", a);
    }
    
    for (i = 0; i <= cont; i++)
    {   
        fil1 = fopen(namefiles[i], "r");
            while (fscanf(namefiles[i], "%lf  %lf", &x, &y) != EOF)
        {
            j++;
            dadosx[j-1] = x;
            dadosy[j-1] = y;
           
        }
    }
    
    for (i = 0; i <= j; i++)
    {
        dadosx[i] += dadosx[i]/(float)cont;
        dadosy[i] += dadosy[i]/(float)cont;
        fprintf(resultados, "%10.5lf %10.5lf", dadosx[i], dadosy[i]);
    }
    

    return 0;
}
