#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double r, xi, x0,xf;
    int n;

    FILE *file;
    file = fopen("dados.dat", "w");

    for (r=2.5; r<=3.99; r+=0.001)
    {
        for (x0 = 0.01; x0 <=0.99; x0+=0.02)
        {
            xi = x0;
            for (n = 1; n <= 100000; n+=1)
            {
                xf = r*xi*(1-xi);
                xi=xf;
            }
            fprintf(file,"%20.8f" "%20.8f\n", r, xi);
        }
        
    }
    

    return 0;
}
