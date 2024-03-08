	#include <stdio.h>
#include <limits.h>
int main() {
    int num;
    int minSeq = INT_MAX; 
    int maxSeq = INT_MIN; 
    printf("Enter a list of numbers terminated by -1:\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        if (num == 0) {
            printf("Minimum: %d, Maximum: %d\n", minSeq, maxSeq);
            minSeq = INT_MAX;
            maxSeq = INT_MIN;
        } else {
            if (num < minSeq) {
                minSeq = num;
            }
            if (num > maxSeq) {
                maxSeq = num;
            }
        }
    }
    return 0;
}

