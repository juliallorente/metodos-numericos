#include <stdio.h>
#include <math.h>

#include "func.h"

void newton (double (*f)(double),double (*df)(double),double x0, int n) {
    for (int i = 0; i < n; i++){
        double dfx0 = df(x0);
        if (dfx0 == 0) {
            printf("Divisão por zero, não foi possível executar a iteração %d do método de Newton.", i+1);
            return;
        } else {
            x0 = x0 - f(x0) / dfx0;
            printf("x_%d = %.16f\n", i + 1, x0);
        }
    }
}

double f (double x) {
    return exp(5*x) - 2;
}

double df(double x) {
    return 5 * exp(5*x);
}

int main() {
    double x0 = 1.64;
    int n = 5;

    // newton(populational_growth, d_populational_growth, x0, n);
    newton(sphere_buoyancy, d_sphere_buoyancy, x0, n);
}


//double g = 9.81, c = 26.19, v = 32.54, t = 7.3;
        //return ((g*x)/c)*( 1 - pow(M_E,-((c/x)*t)) - v);  
        //return 2*x://derivada da função
    //return 3141.59265*x*x-17090.26403*x;
   // double e = exp(-154.0329/x); 

 //double g = 9.81, c = 26.19, v = 32.54, t = 7.3;
      //  return  (g * exp(-(c/x)*t) * (-x * exp((c/x)*t) + c * t + x)/(-c * x));

   // return 6*(exp(x)*((244223*x*x + 63379*x - 63379)+63379))/pow(x,2);
