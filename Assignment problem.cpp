#include <stdio.h>
#include <limits.h>

#define N 5 // Change this value to the number of agents/workers or tasks

void printSolution(int assignmentMatrix[N][N]) {
    printf("Assignment Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", assignmentMatrix[i][j]);
        }
        printf("\n");
    }
}

void subtractMinFromRows(int costMatrix[N][N]) {
    for (int i = 0; i < N; i++) {
        int minVal = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (costMatrix[i][j] < minVal) {
                minVal = costMatrix[i][j];
            }
        }
        for (int j = 0; j < N; j++) {
            costMatrix[i][j] -= minVal;
        }
    }
}

void subtractMinFromCols(int costMatrix[N][N]) {
    for (int j = 0; j < N; j++) {
        int minVal = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (costMatrix[i][j] < minVal) {
                minVal = costMatrix[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            costMatrix[i][j] -= minVal;
        }
    }
}

void assignTasks(int costMatrix[N][N], int assignmentMatrix[N][N], int rowCover[N], int colCover[N], int n) {
    int pathRow[N], pathCol[N];
    int pathCount, row, col;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            assignmentMatrix[row][col] = 0;
        }
        rowCover[row] = 0;
    }

    for (col = 0; col < N; col++) {
        colCover[col] = 0;
    }

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (costMatrix[row][col] == 0 && !rowCover[row] && !colCover[col]) {
                assignmentMatrix[row][col] = 1;
                rowCover[row] = 1;
                colCover[col] = 1;
            }
        }
    }

    for (row = 0; row < N; row++) {
        rowCover[row] = 0;
    }

    for (col = 0; col < N; col++) {
        colCover[col] = 0;
    }

    do {
        pathCount = 0;
        for (col = 0; col < N; col++) {
            if (!colCover[col]) {
                pathRow[pathCount] = -1;
                pathCol[pathCount] = col;
                pathCount++;
                break;
            }
        }
    } while (pathCount == 0);

    int pathFound = 0;

    while (!pathFound) {
        int k;
        for (k = 0; k < N; k++) {
            if (assignmentMatrix[pathRow[pathCount - 1]][k] == 1) {
                break;
            }
        }

        if (k == N) {
            pathFound = 1;
        } else {
            pathRow[pathCount] = pathRow[pathCount - 1];
            pathCol[pathCount] = k;
            pathCount++;
        }

        if (!pathFound) {
            for (int i = 0; i < N; i++) {
                if (assignmentMatrix[pathRow[pathCount - 1]][i] == 1 && !rowCover[i]) {
                    pathRow[pathCount] = i;
                    pathCol[pathCount] = pathCol[pathCount - 1];
                    pathCount++;
                    break;
                }
            }

            if (!pathFound) {
                int minVal = INT_MAX;

                for (int i = 0; i < pathCount; i++) {
                    if (i % 2 == 0) {
                        if (costMatrix[pathRow[i]][pathCol[i]] < minVal) {
                            minVal = costMatrix[pathRow[i]][pathCol[i]];
                        }
                    }
                }

                for (int i = 0; i < pathCount; i++) {
                    if (i % 2 == 0) {
                        costMatrix[pathRow[i]][pathCol[i]] -= minVal;
                    } else {
                        costMatrix[pathRow[i]][pathCol[i]] += minVal;
                    }
                }

                subtractMinFromRows(costMatrix);
                subtractMinFromCols(costMatrix);

                for (int i = 0; i < N; i++) {
                    rowCover[i] = 0;
                    colCover[i] = 0;
                }

                for (int i = 0; i < pathCount; i++) {
                    if (i % 2 == 0) {
                        colCover[pathCol[i]] = 1;
                    } else {
                        rowCover[pathRow[i]] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (assignmentMatrix[i][j] == 1) {
                printf("Assign Worker %d to Task %d\n", i + 1, j + 1);
            }
        }
    }
}

int main() {
    int costMatrix[N][N] = {
        {4, 2, 8, 5, 3},
        {3, 2, 1, 9, 7},
        {6, 4, 8, 2, 5},
        {9, 2, 4, 1, 3},
        {8, 3, 6, 5, 7}
    };

    int assignmentMatrix[N][N];
    int rowCover[N], colCover[N];

    subtractMinFromRows(costMatrix);
    subtractMinFromCols(costMatrix);
    assignTasks(costMatrix, assignmentMatrix, rowCover, colCover, N);

    return 0;
}

