#include<stdio.h>
int reverseNumber(int num) {
    if (num == 0) {
        return 0;
    } else {
        return (num % 10) + 10 * reverseNumber(num / 10);
    }
}
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Reverse of %d is: %d\n", number, reverseNumber(number));
    return 0;
}

