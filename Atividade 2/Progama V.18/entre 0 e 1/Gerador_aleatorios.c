#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    FILE*file;
    file = fopen("tabela.dat", "w");
    int i;
    double r, r2, r3;

    srand(time(NULL));

    r2 = (double)(RAND_MAX);

    for (i = 0; i <= 10000; i++)
    {
        r = (double)rand();
        r3 = r/r2;
        fprintf(file,"%lf\n",r3);
        
    }
    


    return 0;
}
