#include <stdlib.h>;
#include <stdio.h>;
#include <math.h>;

int main(int argc, char const *argv[])
{
    float fx, fxsh, fxdh, h, d1,d2,d3,x;

    x = 2;
    h = 0.1;
    fx = log(x);


    fxsh = log(x+h);
    fxdh = log(x-h);

    d1 = (fxsh - fxdh)/(2*h);
    d2 = (fxsh - fx)/h;
    d3 = 1/x;

    printf("d1 = %f \nd2 = %f \nd3 = %f\n",d1,d2,d3);
    printf("|d1 - d3| = %f \n|d2 - d3| = %f ", fabs(d1-d3), fabs(d2-d3));

    return 0;
}
