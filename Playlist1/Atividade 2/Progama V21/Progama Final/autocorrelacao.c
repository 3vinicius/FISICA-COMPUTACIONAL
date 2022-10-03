#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define RAN() ((double)rand()/(double)(RAND_MAX))
#define pi M_PI

int main()
{
    printf ("oi");
    FILE *fil,*fil1;
    int i,cr;
    double r1,r2,r3,r4,r5,r6;
    double ngau[1000000];
    double hist[100000];
    double xx[100000];

    printf ("oi");
    srand(time(NULL));


    char filename[100]="numerosaleatoriosGAU.dat";
    fil = fopen(filename, "w");

    char filename1[100]="autocorrelacaoGAU.dat";
    fil1 = fopen(filename1, "w");




    for (i = 1; i <= 800000; i++)
    {
        r1 = RAN();
        r2 = RAN();
        r3 = sqrt(-2.*log(r1));
        r4 = cos(2*M_PI*r2);
        r5 = r3*r4;
        ngau[i] = r5;

        fprintf(fil,"%20.8g\n", r5);
    }



    for (cr = 0.; cr <= 10; cr = cr+1)
    {
        r1 = 0.;
        r2 = 0.;
        for (i = 1; i <= (800000 - cr); i = i + 1)
        {
            r1 = r1 + (ngau[i]*ngau[i+cr]);
        }
        for ( i = 1; i <= 800000; i=i+1)
        {
            r2 = r2 + (ngau[i]);
        }

        r1 = r1/(double)(800000-cr);
        r2 = r2/(double)(800000);

        fprintf(fil1, "%20.8lf %20.8lf \n",(double)cr,r1-r2*r2);

    }


    return 0;
}
