#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>



#define RAN()  ((double)rand()/(double)(RAND_MAX))


int main()
{   
    
    
    
    FILE *fil1;
    fil1=fopen("1.dat","w");
    



    double y,x,z,z1,r1,r2,dx,dy;
    int i,N0,i10;
    double dados[100000], NN0[100000] ;

    r1 = 0.;
    i10=0.;
    for (N0 = 2000; N0<=200000; N0+=4000)
    {
        r1=0.;
        i10=i10+1;
        for ( i = 1; i <= N0; i++)
        {
            x = 2.5+(3.*RAN()-1.5);
            y=1.5+(RAN()-0.5);
            z=10.*RAN();
            z1=x/y+y/x;
            if (z<z1) {r1++;}
        }
        


        r1 = r1/(float)N0;
        r1=30*r1;
        dados[i10]=r1;
        NN0[i10] = N0;


    }
    
    r1 = 0.;
    r2 = 0.;
    for (i = i10-10; i <= i10; i++)
    {
        r1=r1+dados[i];
        r2=r2+1;
    }
    r1=r1/r2;
    for ( i = 1; i<=i10; i+=5)
    {
        fprintf(fil1,"%13.8g         %13.8g\n",NN0[i],dados[i]);
    }
    



    return 0;
}
