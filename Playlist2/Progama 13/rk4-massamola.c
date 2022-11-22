#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex.h>

#define P 10000
#define RAN() ((double)rand()/(double)(RAND_MAX))




int main(int argc, char const *argv[])
{
    FILE *fil1,*fil2;
    fil1 = fopen("rk4massamola3dALE.dat","w");
    fil2 = fopen("rk4massamola.dat","w");



    double t,dt,E0,ET,r1,r2,r3,r4;
    int N,i,j;
    double m[P],kmola[P],x[P],v[P],k1x[P],k1v[P],k2x[P],k2v[P],k3x[P],k3v[P],k4x[P],k4v[P];

    N = 100;




    for (i = 0; i <= N; i++)
    {
        x[i]=v[i]=0;
        m[i]=1.+2*RAN();
        kmola[i]=1.;
    }
    

    x[N/2]=1.;
    E0 = 0.;

    for (i = 1; i <= N; i++)
    {
        r1 = pow(x[i]-x[i+1],2.);
        E0=E0+0.5*m[i]*pow(v[i],2.)+0.5*kmola[i]*(r1);
    }



    dt = 0.04;



    for (t = dt; t <= 100.; t+=dt)
    {
        for (i = 1; i <= N; i++)
        {
            k1x[i] = dt*v[i];
            k1v[i] = dt*(1./m[i])*(kmola[i]*x[i+1]+kmola[i-1]*x[i-1]-(kmola[i]+kmola[i-1])*x[i]);
        }
        

        for (i = 1; i <= N; i++)
        {
            k2x[i]=dt*(v[i]+0.5*k1v[i]);
            r1 = x[i+1]+0.5*k1x[i+1];
            r2 = x[i-1]+0.5*k1x[i-1];
            r3 = x[i]+0.5*k1x[i];

            k2v[i] = dt*(1./m[i])*(kmola[i]*r1+kmola[i-1]*r2-(kmola[i]+kmola[i-1])*r3);
        }

        /* k3 */

        for ( i = 1; i <= N; i++)
        {
            k3x[i]=dt*(v[i]+0.5*k2v[i]);
            r1 = x[i+1]+0.5*k2x[i+1];
            r2 = x[i-1]+0.5*k2x[i-1];
            r3 = x[i]+0.5*k2x[i];
            k3v[i] = dt*(1./m[i])*(kmola[i]*r1+kmola[i-1]*r2-(kmola[i]+kmola[i-1])*r3);
        }
        

        /* k4 */
        for ( i = 1; i <= N; i++)
        {
            k4x[i]=dt*(v[i]+k3v[i]);

            r1 = x[i+1]+k3x[i+1];
            r2 = x[i-1]+k3x[i-1];
            r3 = x[i]+k3x[i];
            k4v[i] = dt*(1./m[i])*(kmola[i]*r1+kmola[i-1]*r2-(kmola[i]+kmola[i-1])*r3);
        }
        

        for (i = 1; i <= N; i++)
        {
            x[i] = x[i]+(1./6.)*(k1x[i]+2.*k2x[i]+2.*k3x[i]+k4x[i]);

            v[i] = v[i]+(1./6.)*(k1v[i]+2.*k2v[i]+2.*k3v[i]+k4v[i]);
        }
        
        ET = 0.;
        j++;
        if (j>8)
        {
            for (i = 1; i <= N; i++)
            {
                r1 = pow(x[i]-x[i+1],2.);
                
                r2 = 0.5*m[i]*pow(v[i],2.)+0.5*kmola[i]*(r1);

                ET+=r2;

                fprintf(fil1,"%20.8g %20.8g  %20.8g\n",t,(double)i,r2);
            }
            j = 0;
            fprintf(fil2,"%20.8g %20.8g\n",t,fabs(1-E0/ET));
        }
        
        






    }
    


    




    return 0;
}
