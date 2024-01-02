#include <stdio.h>
#include <stdlib.h>
#include "MatrixOperationsLibrary.h"

int ** init_matrix(int row_numbers, int column_numbers)
{
    //matrix init
    int status = 0;
    int rows = row_numbers;
    int cols = column_numbers;

    printf("row: %d\ncolumn: %d", rows, cols);
    //vector init within matrix
    int ** matrix = malloc(rows * sizeof(int)); //dynamic allocation
    for (int k = 0; k < rows; k++)
    {
        matrix[k] = malloc(cols * sizeof(int));
    }
    
    printf("\nInput each vector elements separated by a space\n");
    for (int j = 0; j < cols; j++) //number of elements in each column/vector depends on the number of rows and vice versa and it has to be iterated for each vector which is the number of columns
    {
        status = 0;
        for (int i = 0; i < rows; i++)
        {
            do
            {
                printf("\nElement %d of Vector %d: ", i+1, j+1);
                status = scanf("%d", &matrix[i][j]);
                int c;
                while (c = getchar() != '\n' && c != EOF);
            } while (status != 1);
        }
    }

    return matrix;
}

int ** addition(int ** matrix1, int row_numbers1, int column_numbers1, int ** matrix2, int row_numbers2, int column_numbers2)
{
    //matrix addition
    if (row_numbers1 == row_numbers2 && column_numbers1 == column_numbers2)
    {
        int ** matrix3 = malloc(row_numbers2 * sizeof(int)); //dynamic allocation
        for (int k = 0; k < row_numbers2; k++)
        {
            matrix3[k] = malloc(column_numbers2 * sizeof(int));
        }
        for (int i = 0; i < row_numbers1; i++)
        {
            for (int j = 0; j < column_numbers1; j++)
            {
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        return matrix3;
    }
    else
    {
        printf("\nMatrices are not the same dimensions. Unable to add up.\n");
    }
    return 0;
}

int ** subtraction(int ** matrix1, int row_numbers1, int column_numbers1, int ** matrix2, int row_numbers2, int column_numbers2)
{
    //matrix subtraction
    if (row_numbers1 == row_numbers2 && column_numbers1 == column_numbers2)
    {
        int ** matrix3 = malloc(row_numbers2 * sizeof(int)); //dynamic allocation
        for (int k = 0; k < row_numbers2; k++)
        {
            matrix3[k] = malloc(column_numbers2 * sizeof(int));
        }
        for (int i = 0; i < row_numbers1; i++)
        {
            for (int j = 0; j < column_numbers1; j++)
            {
                matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }

        return matrix3;
    }
    else
    {
        printf("\nMatrices are not the same dimensions. Unable to subtract.\n");
    }
    return 0;
}

int ** multiplication(int ** matrix1, int row_numbers1, int column_numbers1, int ** matrix2, int row_numbers2, int column_numbers2)
{
    //matrix multiplication
    if (row_numbers1 == column_numbers2 && column_numbers1 == row_numbers2)  //here MxN of A should equal KxL of B  so C matrix should be MxL
    {
        int ** matrix3 = malloc(row_numbers1 * sizeof(int)); //dynamic allocation
        for (int k = 0; k < row_numbers1; k++)
        {
            matrix3[k] = malloc(column_numbers2 * sizeof(int));
        }
        for (int i = 0; i < row_numbers1; i++) //c1 = a1 * b1 + a2 * b2 ... first element of row multiplicatin with first element of column and so on
        {
            for (int j = 0; j < column_numbers2; j++)
            {
                matrix3[i][j] = 0;
                for (int k = 0; k < column_numbers1; k++)
                {
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
            printf("\n");
        }

        return matrix3;
    }
    else
    {
        printf("\nMatrices are not the correct dimensions. Unable to multiply.\n");
    }
    return 0;
}

int ** transposition(int ** matrix, int row_numbers, int column_numbers)
{
    int ** transpose = malloc(column_numbers * sizeof(int)); //dynamic allocation
    for (int k = 0; k < column_numbers; k++)
    {
        transpose[k] = malloc(row_numbers * sizeof(int));
    }
    for (int i = 0; i < row_numbers; i++) //very simple, just switch rows and columns
    {
        for (int j = 0; j < column_numbers; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
    return transpose;
}

int matrix_display(int ** matrix, int row_numbers, int column_numbers)
{
    printf("\nMatrix:\n");
    for (int i = 0; i < row_numbers; i++)
    {
        for (int j = 0; j < column_numbers; j++)
        {
            printf("%4d", matrix[i][j]); //spacing of 4, might need to be bigger if handling matrices with large values
        }
        printf("\n");
    }
}

int free_matrix(int ** matrix, int row_numbers)
{
    if (matrix != NULL)
    {
        for (int i = 0; i < row_numbers; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
    }
}