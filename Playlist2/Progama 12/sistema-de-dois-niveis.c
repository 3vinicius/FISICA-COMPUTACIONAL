#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex.h>






int main(int argc, char const *argv[])
{
    FILE *fil1,fil2;
    fil1 = fopen("2niveisrk4.dat","w");
    


    double r1,r2,r3,r4,eg,ef,tt,t,dt;
    double _Complex f1,f2,g1,g2;
    double _Complex k1f,k2f,k3f,k4f,k1g,k2g,k3g,k4g,ic;




    ic = 0.-1*I;
    ef = eg = 1.;
    tt = 0.1;
    dt = 0.01;
    f1 = 1.+0.*I;
    g1 = 0.+0.*I;



    for (t = (dt); t <= 100; t+=dt)
    {
        k1f = ic*(ef*f1+tt*g1);
        k1g = ic*(eg*g1+tt*f1);
        k2f = ic*(ef*(f1+0.5*dt*k1f)+tt*(g1+0.5*dt*k1g));
        k2g = ic*(eg*(g1+0.5*dt*k1g)+tt*(f1+0.5*dt*k1f));
        k3f = ic*(ef*(f1+0.5*dt*k2f)+tt*(g1+0.5*dt*k2g));
        k3g = ic*(eg*(g1+0.5*dt*k2g)+tt*(f1+0.5*dt*k2f));
        k4f = ic*(ef*(f1+dt*k3f)+tt*(g1+dt*k3g));
        k4g = ic*(eg*(g1+dt*k3g)+tt*(f1+dt*k3f));

        f2 = f1+dt*(1./6.)*(k1f+2.*k2f+2.*k3f+k4f);
        g2 = g1+dt*(1./6.)*(k1g+2.*k2g+2.*k3g+k4g);

        f1 = f2;
        g1 = g2;


        r1 = cabs(f1);
        r2 = cabs(g1);
        r3 = r1*r1+r2*r2;

        fprintf(fil1,"%20.8g %20.8g\n",t,fabs(1.-r3));

    }
    








    return 0;
}
