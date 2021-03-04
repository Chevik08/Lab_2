#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>

#define FULL 1
#define SHOW 2
#define CHANGE 3
#define PREV 4
#define EXIT 5

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

void fulling(float** matrix, int rows, int col)
{
    int warning = 0;
    int* first_arr = (int*)calloc(rows, sizeof(int));
    int* second_arr = (int*)calloc(col, sizeof(int));

    printf("Enter elements of the first array\n");
    for (int i = 0; i < rows; i++)
    {
        first_arr[i] = checker(first_arr[i]);
    }
    printf("Enter elements of the second array\n");
    for (int i = 0; i < col; i++)
    {
        second_arr[i] = checker(second_arr[i]);
    }

    // Поиск дубликатов или чисел меньше 1
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<col; j++)
        {
            if ((first_arr[i] == second_arr[j]) || (first_arr[i] < 1) || (second_arr[j] < 1))
                warning += 1;
        }
    }

    if (warning > 0)
    {
        printf("Incorrect enter\n");
        warning = 0;
    }
    else
    // Присвоение значений
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = pow(((first_arr[i])-(second_arr[j])), -1);
            }
        }
        printf("\n");
    }

    free(first_arr);
    free(second_arr);
}

int main()
{
    int rows = 0;
    int col = 0;
    int message = 0;
    printf("Enter the size of the first array: ");
    rows = checker(rows);
    printf("Enter the size of the second array: ");
    col = checker(col);
    float** matrix = NULL;
    matrix = (float**)calloc(rows, sizeof(float));
    float** new_matrix = NULL;
    new_matrix = (float**)calloc(rows, sizeof(float));
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
        for (int i = 0; i < col; i++)
            free(matrix[i]);
        free(matrix);
        for (int i = 0; i < col; i++)
            free(new_matrix[i]);
        free(new_matrix);

    }
    while (working)
    {
        printf("1. Fulling your matrix\n");
        printf("2. Show your matrix\n");
        printf("3. Change arrays of matrix\n");
        printf("4. See previous matrix\n");
        printf("5. Exit\n");
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
            fulling(matrix, rows, col);
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
            fulling(matrix, rows, col);
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
        case EXIT:
            for (int i = 0; i < col; i++)
                free(matrix[i]);
            free(matrix);
            for (int i = 0; i < col; i++)
                free(new_matrix[i]);
            free(new_matrix);
            printf("Quiting");
            working = 0;
            break;
        default:
            printf("Unusual enter\n");
        }
    }

    return 0;
}
