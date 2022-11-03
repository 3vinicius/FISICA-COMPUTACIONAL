#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>


int main(int argc, char const *argv[])
{
    FILE *fil1,fil2;
    fil1 = fopen("niveisk4v2.dat","w");


    double r1,r2,r3,r4;
    double _Complex cn[2000],cc1,cc2,cc3;
    double _Complex ic,k1[2000],k2[2000],k3[2000],k4[2000];
    double en[2000],eg,ef,tt,t,dt,FT,nm,n2m,m2;
    int i,j,N,i10,i20;

    N=500;
    FT = 1.;

    for (i = 1; i <= N; i++)
    {
        cn[i]=0+0.*I;
        en[i]=0.;

    }


    ic = 0.-1.*I;
    tt=1.;

    dt=0.008;
    i20=(int)(0.025/dt);
    i10=0.;
    cn[N/2]=1./sqrt(2.)+0.*I;
    cn[N/2+1]=1./sqrt(2.)+0.*I;


    for ( t = dt; t <= 300; t+=dt)
    {
        for ( i = 1; i <= N; i++)
        {
            r1 = en[i]+FT*(double)(i-N/2);
            k1[i]=dt*ic*(r1*cn[i]+tt*(cn[i-1]));
        }
        for ( i = 1; i <= N; i+=i)
        {
            cc1=cn[i]+0.5*k1[i];
            cc2=cn[i+1]+0.5*k1[i+1];
            cc3=cn[i-1]+0.5*k1[i-1];
            r1 = en[i]+FT*(double)(i-N/2);
            k2[i]=dt*ic*(r1*cc1+tt*(cc2+cc3));
        }
        for ( i = 1; i <= N; i+=i)
        {
            cc1=cn[i]+0.5*k2[i];
            cc2=cn[i+1]+0.5*k2[i+1];
            cc3=cn[i-1]+0.5*k2[i-1];
            r1 = en[i]+FT*(double)(i-N/2);
            k3[i]=dt*ic*(r1*cc1+tt*(cc2+cc3));
        }

        for ( i = 1; i <= N; i+=i)
        {
            cc1=cn[i]+k3[i];
            cc2=cn[i+1]+k3[i+1];
            cc3=cn[i-1]+k3[i-1];
            r1 = en[i]+FT*(double)(i-N/2);
            k4[i]=dt*ic*(r1*cc1+tt*(cc2+cc3));
        }

        r1=0.;
        for ( i = 1; i <= N; i++)
        {
            cn[i]=cn[i]+(1./6.)*(k1[i]+2.*k2[i]+2.*k3[i]+k4[i]);
            r1=r1+pow(cabs(cn[i]),2.);
        }
        
        i10=i10+1;
        if (i10>i20)
        {
            nm=n2m=m2=0.;
            for ( i = 1; i <=N ; i++)
            {
                nm=nm+((double)(i-N/2))*(pow(cabs(cn[i]),2.));

                n2m=n2m+((double)i)*((double)i)*(pow(cabs(cn[i]),2));
            }
            
        
        



            m2=n2m-nm*nm;

            fprintf(fil1,"%20.8g   %20.8g   %20.8g   %20.8g\n",t,nm,m2,fabs(1.-r1));
            i10=0;
        }
    }
    
    







    return 0;
}
