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
    double a[N][N];
    double p; 
    int z, i,j,k;

    p = 0.40;

    return 0;

    while (z != 300)
    {
    a[N/2][N/2] = 1;
    }
    for (i = -1; i <= 1; i++)
    {

        if (i = 0)
        {
            
            a[N/2][N/2] = RAN();
            a[N/2][N/2-1] = RAN();
            a[N/2][N/2+1] = RAN();
        }
        
        if (i = -1)
        {
            a[N/2-1][N/2] = RAN();
            a[N/2-1][N/2-1] = RAN();
            a[N/2-1][N/2+1] = RAN();
        }
        if (i = 1)
        {
            a[N/2+1][N/2] = RAN();
            a[N/2+1][N/2-1] = RAN();
            a[N/2+1][N/2+1] = RAN();
            
        }
        
    }
    

    for (k = 0; k <= 300; k++)
    {
        if (a[k][k] < p)
        {
            /* code */
        }
        
    }
    

}

