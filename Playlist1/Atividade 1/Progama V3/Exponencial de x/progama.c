#include <stdio.h>;
#include <math.h>;

int main(int argc, char const *argv[])
{
    double y, x, i, j,dx,fat;
    FILE *file;
    FILE *file2;
    file = fopen("exponencial.dat","w");
    file2 = fopen("somatorioj10.dat", "w");

    dx=0.1;
    j = 10;
    for (x = 0.; x <= 2 ; x = x + dx)
    {
        y=1;
        fat = 1;
        for (i = 1; i <= j; i=i+1)
        {
            i = (double)i;
            fat = fat*i;
            y = y+(pow(x,i)/(fat));
        }
        
       fprintf(file, "%20.8f %20.8f\n", x, exp(x));
       fprintf(file2,"%20.8f %20.8f\n", x , y);
    }
    return 0;
}
