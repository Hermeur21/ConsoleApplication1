#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <malloc.h>


int main() {
    int n;
    scanf("%d", &n);

    // динамически выделяемый массив размера n с помощью malloc() и calloc()
    
    int* arr1 = (int*)malloc(n * sizeof(int));
    
    int* arr2 = (int*)calloc(n, sizeof(int));

    if (arr1 == NULL || arr2 == NULL) {
        printf("Memory Error!\n");
    }
    else {
        
        for (int i = 0; i < n; i++) {
            *(arr1 + i) = i;
        }
       
        for (int i = 0; i < n; i++) {
            *(arr2 + i) = n - i;
        }

        // перераспределение динамической памяти указателя
        // другая освобожденная половина теперь будет содержать значения
        int* arr3 = (int*)realloc(arr1, (n / 2) * sizeof(int));

        // перераспределение динамической памяти указателя arr2 для увеличения в два раза
       
        int* arr4 = (int*)realloc(arr2, (2 * n) * sizeof(int));

        if (arr3 == NULL || arr4 == NULL) {
            printf("Reallocation failed!\n");
        }
        else {
            // массива arr1 с использованием указателя
            for (int i = 0; i < n; i++) {
                printf("%d ", *(arr3 + i));
            }

            printf("\n");

            // массива arr2 с использованием указателя
            for (int i = 0; i < 2 * n; i++) {
                printf("%d ", *(arr4 + i));
            }
        }
    }
    return 0;
}