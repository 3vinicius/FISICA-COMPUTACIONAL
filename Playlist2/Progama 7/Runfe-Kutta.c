#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    FILE *fil1,*fil2,*fil3;

    fil1 = fopen("crk2.dat", "w");
    fil2 = fopen("ceuler.dat", "w");
    fil3 = fopen("csolucao.dat", "w");



    double c,f1,f2,g,dx,x0,x,xm;
    double k1,k2,f22,f11;


    x0 = 0.;
    dx = 0.2;
    xm = 10.;
    f1 = 1.;
    f11 = f1;
    c = 0.1;


    for (x = x0+dx; x <= xm; x+=dx)
    {
        k1 = c*f1;
        k2 = c*(f1+0.5*dx*k1);
        f2 = f1 + dx*k2;
        f1 = f2;
        
        f22 = f11+dx*c*f11;
        f11=f22;

        fprintf(fil1,"%13.8f  %13.8f\n",x,f1);
        fprintf(fil2,"%13.8f  %13.8f\n",x,f22);
        fprintf(fil3,"%13.8f  %13.8f\n",x,exp(x*c));
        
    }
    










    return 0;
}
