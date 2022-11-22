#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define PI M_PI





int main(int argc, char const *argv[])
{
    FILE *fil1,*fil2,*fil3;
    fil1 = fopen("verletFPU.dat","w");
    fil2 = fopen("Cenergiaverlet.dat","w");
    fil3 = fopen("especial.dat","w");

    int j,c10,i,n0,n00,c300,c1200,c500;
    double r1,r2,r3,r4,rr3,rr2,UT,U0;
    double kk,m1,mf,kk3,t,tm,dt,v1,v2;
    double xx0[2000],xx1[2000],vx0[2000],vx1[2000];
    double ax0[2000],ax1[2000],energ[2000];

    m1 =1.;
    c10 = 0.;
    c500 = 0.;
    tm = 60.;
    dt=0.0001;
    n0=100.;
    r1=(double)n0;
    r1=r1*0.5;
    n00=(int)r1;

    for ( i = 0; i <= (n0+1); i++)
    {
        xx1[i]=xx0[i]=(double)i;
        vx0[i]=ax0[i]=ax1[i]=vx1[i]=0.;
    }
    

    vx0[n00+25]=1.;
    vx0[n00-25]=-1.;
    rr2 = 0.05/dt;
    c1200 = 3;
    kk = 1.;
    kk3 = 1.;
    U0 = 0.;


    for (i= 1; i <= n0; i++)
    {
        v1=fabs(xx0[i]-xx0[i-1]);
        v2=fabs(xx0[i]-xx0[i+1]);
        r1 = v1-1.;
        r2 = v2-1.;
        r3 = 0.25*kk*(r1*r1+r2*r2);
        r4 = (1./6.)*kk3*(r1*r1*r1+r2*r2*r2);
        U0=U0+r3+r4+0.5*vx0[i]*vx0[i];

    }
    
    for (t = dt; t <= tm; t+=dt)
    {
        for (i = 1; i <= n0; i++)
        {
            v1=fabs(xx0[i]-xx0[i-1]);
            v2=fabs(xx0[i]-xx0[i+1]);
            r1=v1-1.;
            r2=v2-1.;
            ax0[i]=-kk*r1-kk3*(r1*r1)+kk*r2+kk3*(r2*r2);
            xx1[i]=xx0[i]+dt*vx0[i]+dt*dt*ax0[i]*0.5;
        }
        



        for ( i = 1; i <= n0; i++)
        {
            v1 = fabs(xx1[i]-xx1[i-1]);
            v2 = fabs(xx1[i]-xx1[i+1]);
            r1=v1-1.;
            r2=v2-1.;
            ax1[i]=-kk*r1-kk3*(r1*r1)+kk*r2+kk3*(r2*r2);
            vx1[i]=vx0[i]+0.5*dt*(ax0[i]+ax1[i]);

        }
        
        /* for ( i = 1; i <= n0; i++)
        {
            v1 = fabs(xx1[i]-xx1[i-1]);
            v2 = fabs(xx1[i]-xx1[i+1]);
            r1=v1-1.;
            r2 = v2-1;
            ax1[i]=-kk*r1-kk3*(r1*r1)+kk*r2+kk3*(r2*r2);
            vx1[i]=vx0[i]+0.5*dt*(ax0[i]+ax1[i]);

        } */
        
        for ( i = 1; i <= n0; i++)
        {
            vx0[i]=xx1[i];
            vx0[i]=vx1[i];
        }
        



        rr3 = rr3 +1.;
        if (rr3>rr2)
        {
            UT = 0.;
            for (i = 1; i <= n0; i++)
            {
                v1=fabs(xx0[i]-xx0[i-1]);
                v2=fabs(xx0[i]-xx0[i+1]);
                r1=v1-1.;
                r2=v2-1.;
                r3=0.25*kk*(r1*r1+r2*r2);
                r4=(1./6.)*kk3*(r1*r1*r1+r2*r2*r2);
                UT=UT+r3+r4+0.5*vx0[i]*vx0[i];
                energ[i]=(r3+r4+0.5*vx0[i]*vx0[i])/U0;
                fprintf(fil1,"%20.8g %20.8g %20.8g\n",t,(double)i,energ[i]);
            }
            fprintf(fil2,"%20.8g  %20.8g\n",t,fabs(1.-UT/U0));
            rr3=0.;

            c300++;
            if (t>1)c1200=11;
            if(c300>c1200){
           

            c300=0.;
            c500++;

            for (i = 1; i <= n0; i++)
            {
                fprintf(fil3,"%20.8g  %20.8g %20.8g\n",t,(double)i,energ[i]);
            }
            fclose(fil3);
            }
        }
    }
    




    return 0;
}
