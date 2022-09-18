#include <stdio.h>;
#include <stdlib.h>;
#include <math.h>;

int main(int argc, char const *argv[])
{
    double x,y,dx;
    double r1,r2,r3;

    dx = 0.0001;
    y = 0.;

    for (x = 0; x <= 1; x+=dx)
    {
        y = y +(x*x)*dx;
    }

    printf("numerica = %lf",y);
    printf("\nExata = %lf",1/3);
    

    return 0;
}
