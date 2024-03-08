#include <stdio.h>
int isPerfectNumber(int num) {
    int sum = 1; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return (sum == num);
}
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isPerfectNumber(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }
    return 0;
}

