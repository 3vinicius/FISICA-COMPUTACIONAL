#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define RAN()  ((double)rand()/(double)(RAND_MAX))




int main(int argc, char const *argv[])
{
    FILE *fil;
    fil = fopen("montecarlos1.dat","w");

    int i,n;
    double r1,r2,r3,r4;


    for (i = 100000; i <= 22100000; i+=100000)
    {
        r4=0;
        for ( n = 1; n <= i; n++)
        {
            r1 = RAN();
            r2 = RAN();
            r3 = r1*r1+r2*r2;
            r3=sqrt(r3);

            if (r3<1.)
            {
                r4=r4+1.;
            }
            
        }
        

        r4 = r4/(double)n;
        r4 = 4.*r4;
        fprintf(fil,"%20.8g  %20.8g\n",(double)n,r4);
    }
    







    return 0;
}

