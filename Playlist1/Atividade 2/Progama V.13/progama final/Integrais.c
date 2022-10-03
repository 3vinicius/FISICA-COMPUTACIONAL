
int main(){
    double x, dx, a, b;
    double I1, I2, I3, I4;
    double r1,r2,r3;

    dx = 0.05;
    r1 = 0.;
    r2 = 0.;
    r3 = 0.;
    for (x = 0.; x<=1 ; x += dx)
    {
        a = x;
        b = x+dx;

        r1 = (b-a)*(exp((a+b)/2));
        I1 += r1;

        r2 = (b-a)*(exp(a)+exp(b))/2;
        I2 += r2;

        r3 = (b-a)*(exp(a)+4*((exp(a)+exp(b))/2) + exp(b))/6;
        I3 += r3;

    }

    I4 = exp(1) - 1; 

    printf("\nI1 =%11.8f", I1);
    printf("\nI2 =%11.8f", I2);
    printf("\nI3 =%11.8f", I3);
    printf("\nI4 =%11.8f", I4);


}