#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

double ran1(long int *idum);
#define RAN() ((double)rand()/(double)(RAND_MAX))
#define PI M_PI
#define N 300

int main(int argc, char const *argv[])
{
    FILE*fil;
    fil = fopen("tabela.dat","w");
    double a[N][N], na[N][N];
    double p; 
    int z, i,j,k,l;
    int infec,t,total;

    total = 0;
    p = 0.40;
    infec = 0;
    t = 0;
    a[N/2][N/2] = 1;
    a[N/2][N/2] = 1;



    while (total != (N*N))
    {   
        
        for (k = 0; k <= 300; k++)
    {
        for (l = 0; l<=300 ;l++)
        {
        if (na[k][l] = 1)
        {
        infec = 0;
        for (i = -1; i <= 1; i++)
        {
            for (j = -1; j <= 1; j++)
            {
                a[k+i][l+j] = RAN();

                if (a[k+i][l+j] < p)
            {
                a[k+i][l+j] = 1;
                na[k+i][l+j] = a[k+i][l+j];
                infec++;
                total++;
            }
            }
            
        }
        t++;
        fprintf(fil,"%10.d   %10.d",total++);
        }
        }
    }

    }
    
return 0;
}

