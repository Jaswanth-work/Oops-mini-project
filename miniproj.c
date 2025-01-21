#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum size of the matrix

// Function 
void inputMatrix(int mat[MAX][MAX], int rows, int cols);
void displayMatrix(int mat[MAX][MAX], int rows, int cols);
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int rows, int cols);
void subtractMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int rows, int cols);
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int mat[MAX][MAX], int res[MAX][MAX], int rows, int cols);

int main() {
    int choice;
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2;

    do {
        printf("\nMatrix Calculator Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter dimensions of matrices (rows cols): ");
                scanf("%d %d", &rows1, &cols1);
                printf("Enter elements of first matrix:\n");
                inputMatrix(mat1, rows1, cols1);
                printf("Enter elements of second matrix:\n");
                inputMatrix(mat2, rows1, cols1);
                addMatrices(mat1, mat2, result, rows1, cols1);
                printf("Resultant Matrix:\n");
                displayMatrix(result, rows1, cols1);
                break;

            case 2:
                printf("Enter dimensions of matrices (rows cols): ");
                scanf("%d %d", &rows1, &cols1);
                printf("Enter elements of first matrix:\n");
                inputMatrix(mat1, rows1, cols1);
                printf("Enter elements of second matrix:\n");
                inputMatrix(mat2, rows1, cols1);
                subtractMatrices(mat1, mat2, result, rows1, cols1);
                printf("Resultant Matrix:\n");
                displayMatrix(result, rows1, cols1);
                break;

            case 3:
                printf("Enter dimensions of first matrix (rows cols): ");
                scanf("%d %d", &rows1, &cols1);
                printf("Enter dimensions of second matrix (rows cols): ");
                scanf("%d %d", &rows2, &cols2);
                if (cols1 != rows2) {
                    printf("Matrix multiplication not possible with these dimensions.\n");
                } else {
                    printf("Enter elements of first matrix:\n");
                    inputMatrix(mat1, rows1, cols1);
                    printf("Enter elements of second matrix:\n");
                    inputMatrix(mat2, rows2, cols2);
                    multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
                    printf("Resultant Matrix:\n");
                    displayMatrix(result, rows1, cols2);
                }
                break;

            case 4:
                printf("Enter dimensions of the matrix (rows cols): ");
                scanf("%d %d", &rows1, &cols1);
                printf("Enter elements of the matrix:\n");
                inputMatrix(mat1, rows1, cols1);
                transposeMatrix(mat1, result, rows1, cols1);
                printf("Transposed Matrix:\n");
                displayMatrix(result, cols1, rows1);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function definitions
void inputMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int res[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[j][i] = mat[i][j];
        }
    }
}
