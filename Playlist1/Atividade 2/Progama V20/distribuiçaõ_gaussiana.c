#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define RAN() ((double)rand()/(double)(RAND_MAX))

int main(int argc, char const *argv[])
{
    FILE*file;
    FILE*fileh;
 
    file = fopen("tabela.dat", "w");
    fileh = fopen("histograma.dat", "w");
    

    int i;
    double r1,r2,r3,r4,r5,r6;
    float ngau[500000];
    srand(time(NULL));

    for (i = 1; i <= 200000; i++)
    {
        r1 = RAN();
        r2 = RAN();
        r3 = sqrt(-2.*log(r1));
        r4 = cos(2*M_PI*r2);
        r5 = r3*r4;
        ngau[i] = r5;

        fprintf(file,"%20.8lf\n", r5);
        /* fprintf(fileh, "%20.8lf\n", ngau[i]); */
    }
    
    for (r1 = -5; r1 <=5.0 ; r1+=0.1)
    {
        r2 = 0;
        for ( i = 0; i < 200000; i++)
        {
            if (fabs(ngau[i]-r1)<0.05)
            {
                r2++;
            }
        }
        fprintf(fileh, "%20.8lf %20.8lf \n", r1,r2);
    }
    

    return 0;
}
