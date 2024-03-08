#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num, int divisor) {
    if (num <= 1) {
        return false;
    } else if (divisor == 1) {
        return true;
    } else {
        if (num % divisor == 0) {
            return false; 
        } else {
            return isPrime(num, divisor - 1); 
        }
    }
}
void generatePrimes(int limit, int current) {
    if (current <= limit) {
        if (isPrime(current, current / 2)) {
            printf("%d ", current);
        }
        generatePrimes(limit, current + 1);
    }
}
int main() {
    int limit;
    printf("Enter the limit for generating prime numbers: ");
    scanf("%d", &limit);
    printf("Prime numbers up to %d are:\n", limit);
    generatePrimes(limit, 2); // Start with 2, as 1 is not a prime number
    printf("\n");
    return 0;
}

