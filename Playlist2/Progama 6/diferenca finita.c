#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main(int argc, char const *argv[])
{
    FILE *fil;
    fil  = fopen("dados.dat","w");

    double t0,x0,x1,dt,tm,x2;
    double k,m,t;


    t0 = 0.;
    x0 = 0.1;
    x1 = 0.1;
    dt = 0.1;
    tm = 20.;
    k = 1.;
    m = 1.;


    for ( t = t0 = dt; t <= tm; t += dt)
    {
        x2 = 2.*x1-x0-dt*dt*(k/m)*x1;

        x0 = x1;
        x1 = x2;



        fprintf(fil,"%13.8f %13.8f\n",t,x1);
    }
    





    return 0;
}

