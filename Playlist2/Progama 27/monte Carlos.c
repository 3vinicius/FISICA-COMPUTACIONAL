#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define RAN()  ((double)rand()/(double)(RAND_MAX))


int main(int argc, char const *argv[])
{
    double y,x,r1;
    int i,N0;

    r1 = 0.;
    N0 = 4000000;

    for (i = 1; i <= N0; i++)
    {
        x = RAN();
        y = 3.*RAN();

        if (y<(x+2.))
        {
            r1++;
        }
        
    }
    
    r1=r1/(float)N0;
    r1 = 3.*r1;

    printf("%20d  %20.8g",N0,r1);



    return 0;
}
