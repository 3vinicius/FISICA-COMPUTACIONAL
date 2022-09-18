#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    
    double y,x,h,I;


    h = 0.001;
    y = 0;
    for (x = -1; x <= 1-h; x+=h)
    {
        y = (pow(x,3) + pow(x+h,3))*h/2;
    }
    
    printf("%.50lf",I);


    return 0;
}
