#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    FILE*file;
    file = fopen("Inteiros.dat", "w");
    int i, r;

    srand(time(NULL));

    for (i = 0; i <= 10000; i++)
    {
        r = rand();
        fprintf(file,"%d\n",r);
    }
    
    


    return 0;
}
