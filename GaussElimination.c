#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10  // Maximum size of the matrix

void print_matrix(float matrix[MAX][MAX], int n) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%8.2f", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussian_elimination(float matrix[MAX][MAX], int n, float solution[MAX]) {
    // Partial Pivoting and Forward Elimination
    for (int i = 0; i < n; i++) {
        // Partial Pivoting
        int max_row = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(matrix[j][i]) > fabs(matrix[max_row][i])) {
                max_row = j;
            }
        }

        // Swap rows if needed
        if (max_row != i) {
            for (int k = 0; k < n + 1; k++) {
                float temp = matrix[i][k];
                matrix[i][k] = matrix[max_row][k];
                matrix[max_row][k] = temp;
            }
        }

        // Forward Elimination
        for (int j = i + 1; j < n; j++) {
            float factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n + 1; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    print_matrix(matrix, n);

    // Back-Substitution
    for (int i = n - 1; i >= 0; i--) {
        float rhs = matrix[i][n];  // Right-hand side constant
        for (int j = i + 1; j < n; j++) {
            rhs -= matrix[i][j] * solution[j];
        }
        solution[i] = rhs / matrix[i][i];
    }
}

int main() {
    float matrix[MAX][MAX];
    int n;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the coefficients and constants for the system of linear equations:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter row %d (including constant): ", i + 1);
        for (int j = 0; j < n + 1; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Original Matrix:\n");
    print_matrix(matrix, n);

    float solution[MAX];
    gaussian_elimination(matrix, n, solution);

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, solution[i]);
    }

    return 0;
}
