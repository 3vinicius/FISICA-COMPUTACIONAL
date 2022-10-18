#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    FILE *fil1,*fil2;

    fil1 = fopen("crk2SIRINF.dat", "w");
    fil2 = fopen("crk2SIRREC.dat","w");

    double S0,I0,R0,S,I,R,k1S,k2S,k1I,k2I;
    double k1R,k2R,beta,gama,N0,NT,t,dt;

    dt = 0.01;
    N0 = 100.;
    NT = 2e+8;
    I0 = N0/NT;
    R0 = I0;
    S0 = 1.-2.*I0;
    gama = 1./12.;
    beta = 0.4;

    for (t = dt; t <= 100; t += dt)
    {
        k1S = -beta*I0*S0;
        k1I = beta*I0*S0-gama*I0;
        k1R = gama*I0;


        k2S = -beta*(I0+dt*0.5*k1I)*(S0+dt*0.5*k1S);
        k2I = beta*(I0+dt*0.5*k1I)*(S0+dt*0.5*k1S)-gama*(I0+dt*0.5*k1I);
        k2R = gama*(I0+dt*0.5*k1I);

        S = S0 +dt*k2S;
        I = I0 + dt*k2I;
        R = R0 + dt*k2R;


        I0 = I;
        S0 = S;
        R0 = R;



        fprintf(fil1,"%13.8f  %13.8f   %13.8f\n",t,I*100.,I+R+S);
        fprintf(fil2,"%13.8f  %13.8f   %13.8f\n",t,R*100.,I+R+S);




    }
    




    return 0;
}
