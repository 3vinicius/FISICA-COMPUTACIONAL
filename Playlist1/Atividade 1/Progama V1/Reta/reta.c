#include <stdio.h>;
#include<math.h>;

int main(int argc, char const *argv[])
{
    double y,x;

    FILE *file;
    file = fopen("reta2.dat","w");


    for (x = 0; x<=20; x+=3){
        y = x + 1;
        fprintf(file,"%10.2f   %10.2f\n", x,y);
    }

    return 0;
}
