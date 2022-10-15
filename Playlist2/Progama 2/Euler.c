#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    FILE *fil1,*fil2;
    fil1 = fopen("posicao2.dat","w");
    fil2 = fopen("velocidade2.dat","w");

    double v2,v1,m,k,at,t,tm,t0,dt;
    double x2,x1,x0;

    t0 = 0.;
    x0 = 0.1;
    x1=x0;
    dt = 0.005;
    tm = 20.;
    v1 = 0.;
    k = 1.;
    m = 1.;

    for (t = (t0+dt); t <= tm; t+=dt)
    {
        v2 = v1 - dt*(k/m)*x1;
        x2 = x1 + dt*v1;

        v1 = v2;
        x1 = x2;


        fprintf(fil1,"%13.8f %13.8f\n",t,x1);
        fprintf(fil2,"%13.8f %13.8f\n",t,v1);
    }
    
 










    return 0;
}
