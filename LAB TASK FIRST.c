#include <stdio.h>


int main(){
float sub;
float sub2;
float sub3;
float sum;
float per;
printf("give me MARKS OF subject1:\n");
scanf("%f", &sub);
printf("give me MARKS OF subject2:\n");
scanf("%f", &sub2);
printf("give me MARKS OF subject3:\n");
scanf("%f", &sub);
sum = sub + sub2 + sub3;
per = (sum / 300) * 100;
printf("the percentage %.2f ",per);
return 0;
}

