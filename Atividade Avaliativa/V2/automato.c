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
    double a[N][N], na[N][N];
    double p; 
    int z, i,j,k;
    int infec,t;

    p = 0.40;
    infec = 0;
    t = 0;



    while (z != 300)
    {
        a[N/2][N/2] = 1;
        
        for (i = -1; i <= 1; i++)
        {
            for (j = -1; j <= 1; j++)
            {
                a[N/2+i][N/2+j] = RAN();

                if (a[N/2+i][N/2+j] < p)
            {
                na[N/2+i][N/2+j] = a[N/2+i][N/2+j];
                infec++;
            }
            }
            
        }
        t++;
    }

    
    
return 0;
}

