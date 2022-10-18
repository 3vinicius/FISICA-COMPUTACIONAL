#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex.h>

int main(int argc, char const *argv[])
{
    FILE *fil1,*fil2;
    fil1 = fopen("2nivEULER.dat","w");
    fil2 = fopen("2nivelsk2.dat","w");

    double r1,r2,r3,r4;
    double eg,ef,tt,t,dt;
    double _Complex f1,f2,g1,g2;
    double _Complex k1f,k2f,k1g,k2g,ff1;
    double _Complex gg1,ff2,gg2,ic;


    ic = 0.-1.*I;
    ef = eg = 1.;
    tt = 0.01;
    dt = 0.005;
    f1 = 1.+0.*I;
    g1 = 0.+0.*I;
    ff1 = f1;
    gg1 = g1;



    for (t = dt; t <= 100; t+=dt)
    {
        k1f = ic*(ef*f1+tt*g1);
        k1g = ic*(eg*g1+tt*f1);
        k2f = ic*(ef*(f1+0.5*dt*k1f)+tt*(g1+0.5*dt*k1g));
        k2g = ic*(eg*(g1+0.5*dt*k1g)+tt*(f1+0.5*dt*k1f));


        f2 = f1 + dt*k2f;
        g2 = g1 + dt*k2g;

        f1 = f2;
        g1 = g2;


        ff2 = ff1 + dt*ic*(ef*ff1+tt*gg1);
        gg2 = gg1 + dt*ic*(eg*gg1+tt*ff1);
        ff1 = ff2;
        gg1 = gg2;

        r1 = cabs(ff1);
        r2 = cabs(gg1);
        r3 = r1*r1+r2*r2;

     

        fprintf(fil1,"%13.8f  %13.8f\n",t,r1);

        r1 = cabs(f1);
        r2 = cabs(g1);
        r3 = r1*r1+r2*r2;

        fprintf(fil2,"%13.8f   %13.8f\n",t,r1);








    }
    















    return 0;
}
