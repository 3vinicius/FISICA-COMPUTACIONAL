#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <time.h>


double ran1(long int *idum);
#define RAN() ((double)rand()/(double)(RAND_MAX))
#define N 30


int main(int argc, char const *argv[])
{
    FILE*fil;
    fil = fopen("tabela.dat", "w");
    double a[N][N];
    double va[N][N];
    double p;
    int i,j,k,l;
    float n,z;
    int t, infec,total;

    srand(time(NULL));

    p = 0.4;
    a[N/2][N/2] = 1;
   

    while (t != N*N)
    {
        t++;
        i = 0.;
    
        for (i = 1; i <= N; i++)
        {
            j = 0.;
            for ( j = 1; j <= N; j++)
            {   
                va[i][j] = a[i][j];
                z =  va[i][j];
                printf("%f\n", z);
                if (z = 1)
                {
                    
                    k = 0.;
                    for (k = -1; k <= 1 ; k+=1)
                    {
                        l = 0.;
                        for (l = -1; l <= 1; l+=1)
                        {
                            if (a[k+i][l+j] < 1)
                            {
                                n = RAN();
                                a[k+i][l+j] = n;
                                n = (float)n;
                                if ( n <= p)
                                { 
                                    
                                    a[k+i][l+j] = 1;
                                    infec++;
                                    va[k+i][l+j] = 0;
                                    
                                }else{ a[k+i][l+j] = 0;}
                            }
                            
                        }
                        
                    }
                   
                    
                }
                
            }
            
        }
        
        fprintf(fil,"%10.d  %10.d", t, infec);
    }
    


    return 0;
}
