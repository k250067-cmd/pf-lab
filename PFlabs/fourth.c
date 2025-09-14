#include <stdio.h>


int main(){
    int number;

    printf("Enter an integer between 65 and 90: ");
    scanf("%d", &number);

    if (number >= 65 && number <= 90) {
        printf("%d = %c\n", number, number);
    } else {
        printf("Invalid input! Please enter a number between 65 and 90.\n");
    }
        return 0;


}

