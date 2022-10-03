#include <stdio.h>;
#include <math.h>;

int main(int argc, char const *argv[])
{
    double a,b,c;

    b = 6.;
    c = 8.;

    a = sqrt(pow(b,2)+pow(c,2));


    /* a = pow(a, 1/2); */

    printf("%f", a);
    return 0;
}


