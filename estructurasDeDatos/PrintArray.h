//
// Created by Chris on 9/17/17.
//

#ifndef ANALISIS_DE_ALGORITMOS_PRINTARRAY_H
#define ANALISIS_DE_ALGORITMOS_PRINTARRAY_H

#include <cstdio>

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

#endif //ANALISIS_DE_ALGORITMOS_PRINTARRAY_H
