//intgrate numerically using trapezoidal rule

#include<stdio.h>

//Define the function to integrate
double f(double x){
    return x*x; // Example function x^2
}

//function to implement the trapezoidal rule
double trap_intg(double a, double b, int n){
    double h = (b-a)/n; //width of each sub-interval
    double sum = 0.5*(f(a) + f(b)); //sum of the first and last terms

    //sum of the middle terms
    for(int i = 1; i< n; i++){
        double x = a + i*h;
        sum += f(x);
    }

    // multiply the sum by the width of each sub-interval
    return h*sum;
}

int main(){
    double a, b; //Integration limits
    int n; //Number of sub-intervals

    //Get user input for the limits and the number of intervals
    printf("Enter the lower limit of (a):");
    scanf("%lf", &a);
    printf("Enter the upper limit of (b):");
    scanf("%lf", &b);
    printf("Enter the number of sub-intervals(n):");
    scanf("%d", &n);

    //calculate teh approximate integral using trapezioda Rule
    double result = trap_intg(a, b, n);

    //Display the result
    printf("The approximate integral of the function is: %.5f\n", result);

    return 0;
}