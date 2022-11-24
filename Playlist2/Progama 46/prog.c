#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

int main(int argc, char const *argv[])
{
   
    
    FILE *fil;
    fil = fopen("novo.dat","w");
 printf("oi");

    double epsi[500];
    double r1,r2,t,dt,tm,U,del;
    double cn[500][500],A1[500][500];
    double A0[500][500],ic,cconst[30];
    double _Complex cc1,cc2,cc3;
    int i,j,N,n0,l,i10;




    N=200.;
    n0=10.;
    dt=0.05;
    tm = 50.;
    ic = 0.-1*I;
    U=0.;

    cconst[1]=ic*dt;

    for (l = 2; l <= n0; l+=1)
    {
        cconst[l]=ic*dt*cconst[l-1];
    }
    
    r1 =1;
    for (l = 2; l <= n0; l+=1)
    {
        r1=r1*(float)l;
        cconst[l]=cconst[l]/r1;
    }



    for (i = 0; i <= N; i++)
    {
        epsi[i]=0.;
        for ( j = 0; j <= N; j++)
        {
            cn[i][j]=0+0*I;
            A1[i][j]=0+0*I;
            A0[i][j]=0+0*I;
        }
        
    }
    

    cn[N/2][N/2]=1+0*I;
    A0[N/2][N/2]=1+0*I;


    for ( t = dt; t <= tm; t+=dt)
    {
    for ( l = 1; l <= n0; l++)
    {
    for ( i = 1; i <= N; i++)
    {
    for ( j = 1; j <= N; j++)
    {
        cc1=-(A0[i-1][j])+A0[i+1][j]+A0[i][j+1]+A0[i][j-1];
        del=0.;
        if (i==j)
        {
        del =1.;}
        r1 = U*del+epsi[i]+epsi[j];
        cc2=(r1)*A0[i][j];
        A1[i][j]=cc1+cc2;
        }

        
    }

    for (i = 1; i <= N; i++)
    {
    for (j = 1; j <= N; j++)
    {
    cn[i][j]=cn[i][j]+cconst[l]*A1[i][j];
    A0[i][j]=A1[i][j];
    }
    }
    }
    for (i = 1; i <= N; i++)
    {
    for (j = 1; j <= N; j++)
    {
    A0[i][j]=cn[i][j];
    }
    }
       


    i10=i10+1.;
    if (i10>10)
    {
    r1=0.;
    for (i = 1; i <= N; i++)
    {
    for ( j = 1; j <= N; j++)
    {
    r2=fabs(cn[i][j]);
    r1=r1+(r2*r2);
    }
    }
    
    fprintf(fil,"%10.8g  %10.8g\n",t,fabs(1-r1));
    i10=0.;


    }
    
    }
     
   
    




    return 0;
}
