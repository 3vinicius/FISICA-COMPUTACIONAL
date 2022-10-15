#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    FILE *fil, *fil1, *fil2;
    fil = fopen("aproximo1.dat","w");
    fil1 = fopen("aproximo2.dat","w");
    fil2 = fopen("solucao.dat", "w");


    double f1,f2,g0,g1,dx,x0,x,xm,c,f0;

    x0 = 0.;
    dx = 0.1;
    xm = 120.;
    f0 = 1.;
    c = 0.2;

    for (x = (x0+dx); x <= xm; x+=dx )
    {
        g0 = c*f0;
        f1 = f0 + dx*g0;
        fprintf(fil, "%13.8f  %13.8f\n",x,f1);


        g1 = c*f1;
        f2 = f0+0.5*dx*(g0+g1);
        fprintf(fil1,"%13.8f  %13.8f\n",x,f2);

        f0 = f2;

        fprintf(fil2,"%13.8f  %13.8f\n",x,exp(x*c));






    }
    





    return 0;
}
