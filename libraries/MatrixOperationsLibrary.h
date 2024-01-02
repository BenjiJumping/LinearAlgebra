#ifndef MATRIXOPERATIONSLIBRARY_H
#define MATRIXOPERATIONSLIBRARY_H

int ** init_matrix(int row_numbers, int column_numbers);

int ** addition(int ** matrix1, int row_numbers1, int column_numbers1, int ** matrix2, int row_numbers2, int column_numbers2);

int ** subtraction(int ** matrix1, int row_numbers1, int column_numbers1, int ** matrix2, int row_numbers2, int column_numbers2);

int ** multiplication(int ** matrix1, int row_numbers1, int column_numbers1, int ** matrix2, int row_numbers2, int column_numbers2);

int ** transposition(int ** matrix, int row_numbers, int column_numbers);

int matrix_display(int ** matrix, int row_numbers, int column_numbers);

int free_matrix(int ** matrix, int row_numbers);

#endif