#include <stdio.h>
void printReverse(char str[], int index) {
    if (str[index] == '\0') {
        return;
    }
    printReverse(str, index + 1);
    printf("%c", str[index]);
}
int main() {
    char str[] = "Hello, World!";
    printReverse(str, 0);
    printf("\n");
    return 0;
}

