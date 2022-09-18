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
    fileh = fopen("autocorrelacao.dat", "w");
    

    int i,cr;
    double r1,r2,r3,r4,r5,r6;
    float *ngau;
    float *hist;
    float *xx;

    ngau = (float *)(malloc(1000000 * sizeof(float)));
    hist = (float *)(malloc(100000 * sizeof(float)));
    xx = (float *)(malloc(100000 * sizeof(float)));



    srand(time(NULL));

    for (i = 1; i <= 800000; i++)
    {
        r1 = RAN();
        r2 = RAN();
        r3 = sqrt(-2.*log(r1));
        r4 = cos(2*M_PI*r2);
        r5 = r3*r4;
        ngau[i] = r5;

        fprintf(file,"%20.8lf\n", r5);
    }
    
    

    for (cr = 0.; cr <= 10; cr++)
    {
        r1 = 0.;
        r2 = 0.;
        for (i = 1; i <= 800000 - cr; i++)
        {
            r1 = r1+(ngau[i]*ngau[i+cr]);
        }
        for ( i = 1; i <= 800000; i++)
        {
            r2 = r2+(ngau[i]);
        }

        r1 = r1/(float)(800000-cr);
        r2 = r2/(float)(800000);
        fprintf(fileh, "%20.8f %20.8f \n",(float)cr,r1-(r2*r2));

        
    }
    
    

    return 0;
}
