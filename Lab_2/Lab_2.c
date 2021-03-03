#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>

#define ADD 1
#define PROCESS 2
#define SHOW 3
#define CHANGE 4
#define RANDOM 5
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
    return arr_size;

}

int main()
{
    int m = 0;
    int n = 0;
    int message = 0;
    printf("Enter the size of the first array: ");
    m = checker(m);
    printf("Enter the size of the second array: ");
    n = checker(n);
    int** matrix = NULL;
    matrix = (int**)calloc(m, sizeof(int));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int*)calloc(n, sizeof(int));
    }
    while (working)
    {
        printf("3. Show your matrix\n");
        printf("6. Exit\n");
        message = checker(message);
        switch(message)
        {
        case SHOW:
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            break;
        case EXIT:
            for (int i = 0; i < n; i++)
                free(matrix[i]);
            free(matrix);
            printf("Quiting");
            working = 0;
        }
    }

    return 0;
}
