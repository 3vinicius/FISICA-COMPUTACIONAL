#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

int main(int argc, char const *argv[])
{   
    
    FILE *filearq,*fil,*fil1;
    filearq = fopen("nomesdosarquivos.dat","r");
    fil1 = fopen("todosdados.dat","w");

    int quantarq,i,cont;
    char filname[1000];
    float x,y;
    double xt[10000],yt[10000];


    printf("Digite o numero de arquivos\n");
    scanf("%d",&quantarq);


    for (i = 1; i <= quantarq; i++)
    {
            fscanf(filearq,"%s",filname);
            printf("%s\n",filname);
            sprintf(filname, "%s",filname);
            fil = fopen(filname,"r");
             cont = 0;
            if(fil != NULL){
            while (fscanf(fil, "%f" "%f", &x,&y) != EOF)
            {

                cont ++;
                xt[cont-1] += x;
                yt[cont-1] += y;

            }
            }

    
        
    }
    

    for (i = 1; i <= cont; i++)
    {
        fprintf(fil1,"%d   %13.8g\n",i,yt[i-1]/3);
    } 
    


    
    return 0;
}



