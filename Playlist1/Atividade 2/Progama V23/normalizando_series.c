#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{

    FILE*file;
    file = fopen("tabela.dat", "w");

    double r1, r2, max;
    int i;

    srand(time(NULL));
    max = RAND_MAX;

    for (i = 1; i <= 18000; i++)
    {
        r1 = rand()/max;
        r2 = rand()/max;
        fprintf(file,"%10.8f\n",(r1*r2));
    }

    return 0;
}
