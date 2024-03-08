#include <stdio.h>

void printFactors(int n, int i) {
    if (i > n)
        return;

    if (n % i == 0) {
        printf("%d ", i);
    }

    printFactors(n, i + 1);
}

int main() {
    int n;

    // Input the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Display the factors of n using recursion
    printf("Factors of %d are: ", n);
    printFactors(n, 1);

    return 0;
}

