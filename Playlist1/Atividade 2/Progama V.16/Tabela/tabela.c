#include <stdio.h>;
#include <stdlib.h>;
#include <math.h>;

int main(int argc, char const *argv[])
{
    FILE*file;
    file = fopen("tabela.dat", "w");

    double x,y,dx;

    dx = 0.01;
    for (x = -3; x <= 3; x+= dx)
    {
       y = exp(-(x*x));
       fprintf(file,"%10.8f  %10.8f\n", x,y);
    }
    


    return 0;
}
