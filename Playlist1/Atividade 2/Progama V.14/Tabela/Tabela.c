#include <stdlib.h>;
#include <math.h>;
#include <stdio.h>;

int main()
{
    double x, y, dx;
    FILE*file;
    file = fopen("tabela.dat", "w");

    dx = 0.01;
    for (x = 0; x <= 2; x += dx)
    {
       y = x*x;

        fprintf(file, "%10.8f  %10.8f\n", x,y);
    }
    
    return 0;
}
