#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

int main(int argc, char const *argv[])
{   
    
    FILE *fil,*fil1;
    fil = fopen("correlacao.dat","w");
    fil1 = fopen("todos.dat","r");

    int quantarq,i,j,cont;
    float x,y;
    double xt[10000],yt[10000];
    float caixa,mn1,mn2,p;


    cont =0.;
    if(fil1 != NULL){
    while (fscanf(fil1, "%f" "%f", &x, &y) != EOF)
    {

        cont ++;
        xt[cont-1] = x;
        yt[cont-1] = y;

    }
    }


    
    caixa = 1;
    for ( p = 1; p <= 50; p+=caixa)
    {
        mn1 = 0.;
        mn2 = 0.;

        for ( j = 1; j <= (cont-1); j++)
        {
            if ( abs(xt[j]-p) < caixa*0.5)
            {
                mn1+=yt[j];
                mn2++;
            }
            
        }
        

        if (mn2>0)
        {
            fprintf(fil,"%13.8f  %13.8f\n",p,mn1/mn2);
        }
        
    }
    
    
    return 0;
}



