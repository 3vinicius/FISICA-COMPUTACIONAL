#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex.h>

#define P 2000






int main()
{
    FILE *fil1;
    fil1 = fopen("Nnivelsk4v2.dat","w");



    double r1,r2,r3,r4,eg,ef,tt,t,dt;
    int i,j,N;
    double en[P];
    double _Complex cn[P],k1[P],k2[P];
    double _Complex k3[P],k4[P];
    double _Complex cc1,cc2,cc3,ic;
    double nm,n2m,m2;
    N = 1000;


    for ( i = 1; i <= N; i++)
    {
        cn[i]=0.+0.*I;
        en[i]=0.; 
    }
    

    ic = 0.-1.*I;
    tt = 1.;
    dt = 0.01;
    cn[N/2]=1.+0.*I;




    for (t = dt; t <= 100; t+=dt)
    {
        for (i = 1; i <= N; i++)
        {
            k1[i]=dt*ic*(en[i]*cn[i]+tt*(cn[i+1]+cn[i-1]));
        }
        
        for (i = 1; i <= N; i++)
        {
            cc1 = cn[i]+0.5*k1[i];
            cc2 = cn[i+1]+0.5*k1[i+1];
            cc3 = cn[i-1]+0.5*k1[i-1];
            k2[i]=dt*ic*(en[i]*cc1+tt*(cc2+cc3));
        }
        
        for ( i = 1; i <= N; i++)
        {
            cc1=cn[i]+0.5*k2[i];
            cc2=cn[i+1]+0.5*k2[i+1];
            cc3=cn[i-1]+0.5*k2[i-1];
            k3[i]=dt*ic*(en[i]*cc1+tt*(cc2+cc3));
        }
        
        for (i = 1; i <= N; i++)
        {
            cc1=cn[i]+k3[i];
            cc2=cn[i+1]+k3[i+1];
            cc3=cn[i-1]+k3[i-1];
            k4[i]=dt*ic*(en[i]*cc1+tt*(cc2+cc3));
        }
        
        r1 = 0.;

        for (i = 1; i <= N; i++)
        {
            cn[i]=cn[i]+(1./6.)*(k1[i]+2.*k2[i]+2.*k3[i]+k4[i]);

            r1=r1+pow(cabs(cn[i]),2.);
        }
        



      nm=n2m=m2=0.;
        for ( i = 1; i <= N; i++)
        {
            nm+=((double)i)*(pow(cabs(cn[i]),2.));

            n2m+=((double)i)*((double)i)*(pow(cabs(cn[i]),2.));
        }
         
        m2 = n2m-nm*nm; 



        fprintf(fil1,"%20.8g  %20.8g  %20.8g\n",t, m2, fabs(1.-r1));


    }
    




    return 0;
}
