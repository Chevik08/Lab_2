#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>

#define FULL 1
#define SHOW 2
#define CHANGE 3
#define PREV 4
#define DET 5
#define EXIT 6

int working = 1;

int checker(int arr_size)
/* Функция для проверки чисел на натуральность,
пробелы и символы */
{
    char example_el;
    if (isdigit(scanf("%d", &arr_size)))
        printf("Hello");
    while (example_el != '\n')
    {
        if (arr_size <= 0)
        {
            arr_size = -1;
            break;
        }
        else if (isalpha(example_el))
        {
            arr_size = -1;
            break;
        }
        else if (example_el == ' ')
        {
            printf("Incorrect enter");
            arr_size = -1;
            break;
        }
        scanf("%c", &example_el);
    }
    while (example_el != '\n')
    {
        scanf("%c", &example_el);
    }

    if (arr_size < 0)
    {
        working = 0;
    }
    return arr_size;

}

void fulling(float** matrix, int rows, int col, int* first_array, int* second_array)
// Заполнение матрицы значениями
{
    int warning = 0;
    int check = 0;

    printf("Enter elements of the first array\n");
    for (int i = 0; i < rows; i++)
    {
        check = checker(first_array[i]);
        if (check != -1)
            first_array[i] = check;
        else
            warning += 1;
    }
    check = 0;
    printf("Enter elements of the second array\n");
    for (int i = 0; i < col; i++)
    {
        check = checker(second_array[i]);
        if (check != -1)
            second_array[i] = check;
        else
            warning += 1;
    }

    // Поиск дубликатов или чисел меньше 1
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<col; j++)
        {
            if ((first_array[i] == second_array[j]) || (first_array[i] < 1) || (second_array[j] < 1))
                warning += 1;
        }
    }
    if (warning > 0)
    {
        printf("Incorrect enter\n");
        warning = 0;
        working = 0;
    }
    else
    // Присвоение значений
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = pow(((first_array[i])-(second_array[j])), -1);
            }
        }
        printf("\n");
    }
}

void det(int* first_arr, int* second_arr, int rows, int col)
{
    int first_mul = 1;
    int second_mul = 1;
    for (int i = 1; i < col; i++)
        for (int j = 0; j < col-1; j++)
        {
            first_mul *= (first_arr[i] - first_arr[j])*(second_arr[j] - second_arr[i]);
        }

    for (int i = 0; i < col; i++)
        for (int j = 0; j < col; j++)
        {
            second_mul *= (first_arr[i] - second_arr[j]);
        }
    printf("Your determinant:");
    printf("%.8f\n", (float)first_mul/second_mul);
}

int main()
// Функция для реализации меню
{
    int rows = 0;
    int col = 0;
    int message = 0;
    printf("Enter the size of the first array: ");
    rows = checker(rows);
    printf("Enter the size of the second array: ");
    col = checker(col);
    float** matrix = NULL;
    matrix = (float**)calloc(rows, sizeof(float*));
    float** new_matrix = NULL;
    new_matrix = (float**)calloc(rows, sizeof(float*));
    int* first_arr = (int*)calloc(rows, sizeof(int));
    int* second_arr = (int*)calloc(col, sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (float*)calloc(col, sizeof(float));
    }
    for (int i = 0; i < rows; i++)
    {
        new_matrix[i] = (float*)calloc(col, sizeof(float));
    }

    if (working == 0)
    {
        printf("Incorrect enter\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Quiting\n");
    }
    while (working)
    {
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("1. Fulling your matrix\n");
        printf("2. Show your matrix\n");
        printf("3. Change arrays of matrix\n");
        printf("4. See previous matrix\n");
        printf("5. Calculate the det\n");
        printf("6. Exit\n");
        message = checker(message);
        switch(message)
        {
        case FULL:
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    new_matrix[i][j] = 0;
                    new_matrix[i][j] += matrix[i][j];
                }
            }
            fulling(matrix, rows, col, first_arr, second_arr);
            break;
        case SHOW:
            printf("Your array\n");
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    printf("%.2f ", matrix[i][j]);
                }
                printf("\n");
            }
            break;
        case CHANGE:
            for (int i = 0; i < rows; i++)
                free(matrix[i]);
            free(matrix);
            for (int i = 0; i < rows; i++)
                free(new_matrix[i]);
            free(new_matrix);
            free(first_arr);
            free(second_arr);
            main();
            break;
        case PREV:
            printf("Your array\n");
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    printf("%.2f ", new_matrix[i][j]);
                }
                printf("\n");
            }
            break;
        case DET:
            det(first_arr, second_arr, rows, col);
            break;
        case EXIT:
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("Quiting\n");
            working = 0;
            break;
        default:
            printf("Unusual enter\n");
        }
    }
    // Очистка массивов
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    for (int i = 0; i < rows; i++)
        free(new_matrix[i]);
    free(new_matrix);
    free(first_arr);
    free(second_arr);

    return 0;
}
