#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <time.h>


double ran1(long int *idum);
#define RAN() ((double)rand()/(double)(RAND_MAX))
#define N 300


int main(int argc, char const *argv[])
{
    FILE*fil;
    fil = fopen("tabela.dat", "w");
    double a[N][N];
    double va[N][N];
    double p;
    int z,i,j,k,l;
    int t, infec,total;

    srand(time(NULL));

    p = 0.4;
    a[N/2][N/2] = 1;
    va[N/2][N/2] = 1;
   

    while (t != N)
    {
        t++;
        i = 0.;
        
        for (i = 1; i <= N; i++)
        {
            j = 0.;
            for ( j = 1; j <= N; j++)
            {
                if (va[i][j] = 1)
                {
                    k = 0.;
                    for (k = -1; k <= 1 ; k+=1)
                    {
                        l = 0.;
                        for (l = -1; l <= 1; l+=1)
                        {
                            if (a[k+i][l+j]<1)
                            {
                                a[k+i][l+j] = RAN();

                                if ( (a[k+i][l+j]) <= p)
                                {
                                    va[k+i][l+j] = 1;
                                    a[k+i][l+j] = 1;
                                    infec++;
                                }
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        total += infec;
        fprintf(fil,"%10.d   %10.d\n",t,total);
        
    }
    


    return 0;
}
