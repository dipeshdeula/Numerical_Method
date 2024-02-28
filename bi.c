#include<stdio.h>
#include<math.h>

//create a function 

double f(double x){
    return sin(x)+2;
}

int main(){
    double a,b,m,product,error,prev;
    int iteration=0;

    do{
        printf("Enter the value of a and b:");
        scanf("%lf %lf",&a,&b);
        product=f(a)*f(b);

        if(product<0){
            break;
        }
        else if(product==0){
            printf("The root value is %lf:",f(a)==0?a:b);
            return 0;
        }
        else if(product>0){
            printf("Re-enter the initial guess");
        }
    }while(1);

    do{
        iteration++;

        if(iteration>0){
            prev=m;
        }
        m=(a+b)/2;
        
        if(f(m)*f(a)){
            b=m;
        }else{
            a=m;
        }
        error=fabs(m-prev)/m;
        
    }while(fabs(error>0.001));
    printf("The root value is %lf",m);

}