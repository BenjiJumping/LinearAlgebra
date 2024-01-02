#include <stdio.h>
#include <stdlib.h>

int ** init_matrix(int * row_numbers, int * column_numbers);
int operations(int ** matrix, int row_numbers, int column_numbers);
int addition(int ** matrix, int row_numbers, int column_numbers);
int subtraction(int ** matrix, int row_numbers, int column_numbers);
int multiplication(int ** matrix, int row_numbers, int column_numbers);
int transposition(int ** matrix, int row_numbers, int column_numbers);
int matrix_display(int ** matrix, int row_numbers, int column_numbers);

int main(void)
{
    int row_numbers, column_numbers;
    int ** matrix = init_matrix(&row_numbers, &column_numbers);
    operations(matrix, row_numbers, column_numbers);
    //free(); //free matrix recursively
    return 0;
}

int ** init_matrix(int * row_numbers, int * column_numbers)
{
    //matrix init
    int status = 0;
    int rows, cols;
    do
    {
        printf("How many rows and columns (MxN) does the matrix have? Separate the numbers with a space: ");
        status = scanf("%d %d", &rows, &cols);
        int c;
        while (c = getchar() != '\n' && c != EOF);
    } while (status != 2 || rows < 0 || cols < 0);

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

    * row_numbers = rows;
    * column_numbers = cols;

    return matrix;
}

int operations(int ** matrix, int row_numbers, int column_numbers)
{
    int status = 0;
    int choice;
    printf("\nMatrix:\n");
    matrix_display(matrix, row_numbers, column_numbers);
    do
    {
        printf("Pick an operation you'd like to perform on the matrix:\n1) Addition\n2) Subtraction\n3) Multiplication\n4) Transposition\n5) Reset\n");
        status = scanf("%d", &choice);
        int c;
        while (c = getchar() != '\n' && c != EOF);
    } while (status != 1 || choice < 1 || choice > 5);
    
    if (choice == 1)
    {
        addition(matrix, row_numbers, column_numbers);
    }
    else if (choice == 2)
    {
        subtraction(matrix, row_numbers, column_numbers);
    }
    else if (choice == 3)
    {
        multiplication(matrix, row_numbers, column_numbers);
    }
    else if (choice == 4)
    {
        transposition(matrix, row_numbers, column_numbers);
    }
    else if (choice == 5)
    {
        main();
    }
}

int addition(int ** matrix, int row_numbers, int column_numbers)
{
    int ** matrix1 = matrix;
    int status = 0;
    int rows, cols;
    do
    {
        printf("How many rows and columns (MxN) does the second matrix have? Separate the numbers with a space: ");
        status = scanf("%d %d", &rows, &cols);
        int c;
        while (c = getchar() != '\n' && c != EOF);
    } while (status != 2 || rows < 0 || cols < 0);

    printf("row: %d\ncolumn: %d", rows, cols);
    //vector init within matrix
    int ** matrix2 = malloc(rows * sizeof(int)); //dynamic allocation
    for (int k = 0; k < rows; k++)
    {
        matrix2[k] = malloc(cols * sizeof(int));
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
                status = scanf("%d", &matrix2[i][j]);
                int c;
                while (c = getchar() != '\n' && c != EOF);
            } while (status != 1);
        }
    }
    printf("\n\n");
    //matrix addition
    if (row_numbers == rows && column_numbers == cols)
    {
        int ** matrix3 = malloc(rows * sizeof(int)); //dynamic allocation
        for (int k = 0; k < rows; k++)
        {
            matrix3[k] = malloc(cols * sizeof(int));
        }
        for (int i = 0; i < row_numbers; i++)
        {
            for (int j = 0; j < column_numbers; j++)
            {
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        //matrix operation display
        matrix_display(matrix1, row_numbers, column_numbers);
        printf("\n+\n\n");
        matrix_display(matrix2, row_numbers, column_numbers);
        printf("\n=\n\n");
        matrix_display(matrix3, row_numbers, column_numbers);

        //revert back to 
        operations(matrix3, row_numbers, column_numbers);
    }
    else
    {
        printf("\nMatrices are not the same dimensions. Unable to add up.\n");
        operations(matrix1, row_numbers, column_numbers);
    }
}

int subtraction(int ** matrix, int row_numbers, int column_numbers)
{
    int ** matrix1 = matrix;
    int status = 0;
    int rows, cols;
    do
    {
        printf("How many rows and columns (MxN) does the second matrix have? Separate the numbers with a space: ");
        status = scanf("%d %d", &rows, &cols);
        int c;
        while (c = getchar() != '\n' && c != EOF);
    } while (status != 2 || rows < 0 || cols < 0);

    printf("row: %d\ncolumn: %d", rows, cols);
    //vector init within matrix
    int ** matrix2 = malloc(rows * sizeof(int)); //dynamic allocation
    for (int k = 0; k < rows; k++)
    {
        matrix2[k] = malloc(cols * sizeof(int));
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
                status = scanf("%d", &matrix2[i][j]);
                int c;
                while (c = getchar() != '\n' && c != EOF);
            } while (status != 1);
        }
    }

    //matrix subtraction
    if (row_numbers == rows && column_numbers == cols)
    {
        int ** matrix3 = malloc(rows * sizeof(int)); //dynamic allocation
        for (int k = 0; k < rows; k++)
        {
            matrix3[k] = malloc(cols * sizeof(int));
        }
        for (int i = 0; i < row_numbers; i++)
        {
            for (int j = 0; j < column_numbers; j++)
            {
                matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
            }
            printf("\n");
        }
        //matrix operation display
        matrix_display(matrix1, row_numbers, column_numbers);
        printf("\n-\n\n");
        matrix_display(matrix2, row_numbers, column_numbers);
        printf("\n=\n\n");
        matrix_display(matrix3, row_numbers, column_numbers);

        //revert back to 
        operations(matrix3, row_numbers, column_numbers);
    }
    else
    {
        printf("\nMatrices are not the same dimensions. Unable to subtract.\n");
        operations(matrix1, row_numbers, column_numbers);
    }
}

int multiplication(int ** matrix, int row_numbers, int column_numbers)
{
    int ** matrix1 = matrix;
    int status = 0;
    int rows, cols;
    do
    {
        printf("How many rows and columns (MxN) does the second matrix have? Separate the numbers with a space: ");
        status = scanf("%d %d", &rows, &cols);
        int c;
        while (c = getchar() != '\n' && c != EOF);
    } while (status != 2 || rows < 0 || cols < 0);

    printf("row: %d\ncolumn: %d", rows, cols);
    //vector init within matrix
    int ** matrix2 = malloc(rows * sizeof(int)); //dynamic allocation
    for (int k = 0; k < rows; k++)
    {
        matrix2[k] = malloc(cols * sizeof(int));
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
                status = scanf("%d", &matrix2[i][j]);
                int c;
                while (c = getchar() != '\n' && c != EOF);
            } while (status != 1);
        }
    }

    //matrix multiplication
    if (row_numbers == cols && column_numbers == rows)  //here MxN of A should equal KxL of B  so C matrix should be MxL
    {
        int ** matrix3 = malloc(row_numbers * sizeof(int)); //dynamic allocation
        for (int k = 0; k < row_numbers; k++)
        {
            matrix3[k] = malloc(cols * sizeof(int));
        }
        for (int i = 0; i < row_numbers; i++) //redo, c1 = a1 * b1 + a2 * b2 ... first row summult with first column 
        {
            for (int j = 0; j < cols; j++)
            {
                matrix3[i][j] = 0;
                for (int k = 0; k < column_numbers; k++)
                {
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
            printf("\n");
        }
        //matrix operation display
        matrix_display(matrix1, row_numbers, column_numbers);
        printf("\n*\n\n");
        matrix_display(matrix2, rows, cols);
        printf("\n=\n\n");
        matrix_display(matrix3, row_numbers, cols);

        //revert back to 
        operations(matrix3, row_numbers, cols);
    }
    else
    {
        printf("\nMatrices are not the correct dimensions. Unable to multiply.\n");
        operations(matrix1, row_numbers, column_numbers);
    }
}

int transposition(int ** matrix, int row_numbers, int column_numbers)
{
    int ** transpose = malloc(column_numbers * sizeof(int)); //dynamic allocation
    for (int k = 0; k < column_numbers; k++)
    {
        transpose[k] = malloc(row_numbers * sizeof(int));
    }
    for (int i = 0; i < row_numbers; i++)
    {
        for (int j = 0; j < column_numbers; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
    matrix_display(transpose, column_numbers, row_numbers);
    operations(transpose, column_numbers, row_numbers);
}

int matrix_display(int ** matrix, int row_numbers, int column_numbers)
{
    for (int i = 0; i < row_numbers; i++)
    {
        for (int j = 0; j < column_numbers; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}