#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define RAN()  ((double)rand()/(double)(RAND_MAX))
double ran1(long int *idum);



int main(int argc, char const *argv[])
{
    /* FILE *fil;
    fil = fopen("montecarlos2.dat","w");
 */
    int i,n;
    double r1,r2,r3,r4;
    long int SEED;

    SEED = -1;
    n = 100000;
   /*  for (n = 100000; n <= 22100000; n+=100000)
    { */
        r4=0;
        for ( i = 1; i <= n; i++)
        {
            r1 = ran1(&SEED);
            r2 = ran1(&SEED);
            r3 = r1*r1+r2*r2;
            r3=sqrt(r3);

            if (r3<1.)
            {
                r4=r4+1.;
            }
            
        }
        

        r4 = r4/(double)n;
        r4 = 4.*r4;
        printf("%20.8g  %20.8g\n",(double)n,r4);
   /*  } */
    







    return 0;
}

