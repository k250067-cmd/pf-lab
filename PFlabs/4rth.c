include <stdio.h>


int main(){
    float basicSalary;
    float HRA;
    float DA;
    float grossSalary;



    printf("enter your basicSalary:");
    scanf("%f", &basicSalary);
    HRA = basicSalary * 0.1;
    DA = basicSalary * 0.05;
    grossSalary = basicSalary + HRA + DA;
    printf("GROSS SALARY IS .2%f", grossSalary);
    return 0;
