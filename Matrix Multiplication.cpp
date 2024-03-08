#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100
void multiply_matrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) 
{
    for (int i = 0; i < rows1; ++i) 
    {
        for (int j = 0; j < cols2; ++j) 
	   {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) 
		  {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void print_matrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
	   {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    printf("Enter dimensions of Matrix 1 (rows columns): ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter dimensions of Matrix 2 (rows columns): ");
    scanf("%d %d", &rows2, &cols2);
    if (cols1 != rows2) 
    {
        printf("Invalid matrix dimensions for multiplication. Columns of Matrix 1 must be equal to rows of Matrix 2.\n");
        return 1;
    }
    printf("Enter elements of Matrix 1:\n");
    for (int i = 0; i < rows1; ++i) 
    {
        for (int j = 0; j < cols1; ++j) 
	   {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements of Matrix 2:\n");
    for (int i = 0; i < rows2; ++i) 
    {
        for (int j = 0; j < cols2; ++j) 
	   {
            scanf("%d", &mat2[i][j]);
        }
    }
    clock_t start_time = clock();
    multiply_matrices(mat1, mat2, result, rows1, cols1, rows2, cols2);
    clock_t end_time = clock();
    double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nMatrix 1:\n");
    print_matrix(mat1, rows1, cols1);
    printf("\nMatrix 2:\n");
    print_matrix(mat2, rows2, cols2);
    printf("\nResult Matrix:\n");
    print_matrix(result, rows1, cols2);
    printf("\nExecution Time: %f seconds\n", execution_time);
    return 0;
}

