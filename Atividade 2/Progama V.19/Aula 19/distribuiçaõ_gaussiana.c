#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define RAN() ((double)rand()/(double)(RAND_MAX))

int main(int argc, char const *argv[])
{
    FILE*file;
    file = fopen("tabela.dat", "w");

    int i;
    double r1,r2,r3,r4,r5,r6;
    srand(time(NULL));

    for (i = 1; i <= 200000; i++)
    {
        r1 = RAN();
        r2 = RAN();
        r3 = sqrt(-2.*log(r1));
        r4 = cos(2*M_PI*r2);
        r5 = r3*r4;

        fprintf(file,"%20.8lf\n", r5);
    }
    


    return 0;
}
