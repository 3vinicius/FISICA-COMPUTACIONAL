#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    FILE *fil1,*fil2;
    fil1 = fopen("aproximadoadms4.dat","w");
    fil2 = fopen("csolucao.dat","w");

    double f0,f1,f2,f3,f4,x;
    double y0,y1,y2,y3,x0,x1,x2,x3,dx,x4,xm,c,y4;


    x0 = 0.;
    dx = 0.1;
    xm = 30.;
    y0 = 1.;
    c = 0.2;
    f0 = c*y0;
    y1 = y0+dx*f0;
    f1 = c*y1;
    y2 = y1+dx*f1;
    f2 = c*y2;
    y3=y2+dx*f2;
    f3 = c*y3;





    for (x = (4.*dx); x <= xm; x+=dx)
    {
        y4 = y3+(dx/24.)*(55.*f3-59.*f2+37.*f1-9.*f0);
        f4 = c*y4;
        y4 = y3 + (dx/24.)*(9.*f4+19.*f3-5.*f2+f1);
        f4 = c*y4;

        f0 = f1;
        f1 = f2;
        f2 = f3;
        f3 = f4;
        y3 = y4;




        fprintf(fil1, "%13.8f   %13.8f\n",x,y3);

        fprintf(fil2,"%13.8f   %13.8f\n",x,exp(c*x));

    }
    





    return 0;
}
