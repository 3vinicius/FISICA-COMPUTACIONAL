#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    FILE *fil1,*fil2,*fil3;
    fil1 = fopen("caprocimadoadams.dat","w");
    fil2 = fopen("csolucao.dat","w");

    double f1,f2,g0,g1,dx,x0,x,xm,c,f0;


    x0 = 0.;
    dx = 0.1;
    xm = 20.;
    f0 = 1.;
    c = 0.2;
    g0 = c*f0;
    f1 = f0+dx*g0;
    g1 = c*f1;
    f2 = f1+dx*g1;
    f1 = f2;


    for (x = (3.*dx); x <= xm; x+=dx)
    {
        f2 = f1 + 0.5*dx*(3.*g1-g0);
        g0 = g1;
        g1 = c*f2;
        f1 = f2;


        fprintf(fil1,"%13.8f   %13.8f\n",x,f1);
        fprintf(fil2,"%13.8f  %13.8f\n",x,exp(c*x));
    }
    










    return 0;
}
