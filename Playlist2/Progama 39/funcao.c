#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

int main(int argc, char const *argv[])
{
    FILE *fil;
    fil = fopen("dados.dat", "w");
    double y,x;
    int i;

    for (i = 1; i <= 20; i++)
    {
        y = pow(i,2)+3;
        fprintf(fil,"%d  %10.8f\n", i,y);
    }
    
    return 0;
}
