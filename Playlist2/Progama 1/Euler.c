#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    FILE *fil1,*fil2;
    fil1 = fopen("dados3.dat", "w");
    fil2 = fopen("dados.dat", "w");

    double f1,f2,g,dx,x0,x,xm;

    x0 = 0;
    dx = 0.005;
    xm = 10.;
     f1 = 1.;

    for (x = x0; x <= xm; x += dx)
    {
        g = exp(x-dx);
        f2 = f1 + (dx*g);
        f1 = f2;

        fprintf(fil1, "%13.8f  %13.8f\n", x,f1);
        fprintf(fil2,"%13.8f %13.8f\n",x,exp(x));
    }
    




    return 0;
}
