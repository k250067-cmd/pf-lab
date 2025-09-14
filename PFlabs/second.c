
#include <stdio.h>


int main(){
int a,b,temp;
printf("give me a num:");
scanf("%d", &a);
printf("give me a num:");
scanf("%d", &b);
temp = a;
a = b;
b = temp;

printf("after swapping first number %d \n",a);
printf("after swapping second number %d \n4",b);
return 0;

}
