//
// Created by Chris on 9/15/17.
//

#ifndef ANALISIS_DE_ALGORITMOS_MERGESORT_H
#define ANALISIS_DE_ALGORITMOS_MERGESORT_H

#include<stdlib.h>
#include<stdio.h>
#include <chrono>
#include "Grapher.h"
#include <iostream>


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void pruebaMergeSort(){
    //Inicia Prueba------------------------------------------------------------------------------
    double valoresPruebasX[6]= {25,50,100,200,400,800};
    double valoresPruebasY[6];
    int prueba25[25];
    int prueba50[50];
    int prueba100[100];
    int prueba200[200];
    int prueba400[400];
    int prueba800[800];


    int n25 = sizeof(prueba25)/sizeof(prueba25[0]);
    int n50 = sizeof(prueba50)/sizeof(prueba50[0]);
    int n100 = sizeof(prueba100)/sizeof(prueba100[0]);
    int n200 = sizeof(prueba200)/sizeof(prueba200[0]);
    int n400 = sizeof(prueba400)/sizeof(prueba400[0]);
    int n800 = sizeof(prueba800)/sizeof(prueba800[0]);


    for (int i = 0; i < 25; ++i) {
        prueba25[i] = rand() % 10 + 1;
    }
    for (int i = 0; i < 50; ++i) {
        prueba50[50] = rand() % 10 + 1;
    }
    for (int i = 0; i < 100; ++i) {
        prueba100[100] = rand() % 10 + 1;
    }
    for (int i = 0; i < 200; ++i) {
        prueba200[200] = rand() % 10 + 1;
    }
    for (int i = 0; i < 400; ++i) {
        prueba400[400] = rand() % 10 + 1;
    }
    for (int i = 0; i < 800; ++i) {
        prueba800[800] = rand() % 10 + 1;
    }

    //------------------------------------------------------------------
    auto start25 = std::chrono::high_resolution_clock::now();
    mergeSort(prueba25,0,n25-1);
    auto end25 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff25 = end25 - start25;

    std::cout << diff25.count()*1000 << std::endl;

    valoresPruebasY[0] = diff25.count()*1000;
    //------------------------------------------------------------------
    auto start50 = std::chrono::high_resolution_clock::now();
    mergeSort(prueba50,0,n50-1);
    auto end50 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff50 = end50 - start50;

    std::cout << diff50.count()*1000 << std::endl;

    valoresPruebasY[1] = diff50.count()*1000;
    //------------------------------------------------------------------
    auto start100 = std::chrono::high_resolution_clock::now();
    mergeSort(prueba100,0,n100-1);
    auto end100 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff100 = end100 - start100;

    std::cout << diff100.count()*1000 << std::endl;

    valoresPruebasY[2] = diff100.count()*1000;
    //------------------------------------------------------------------
    auto start200 = std::chrono::high_resolution_clock::now();
    mergeSort(prueba200,0,n200-1);
    auto end200 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff200 = end200 - start200;

    std::cout << diff200.count()*1000 << std::endl;

    valoresPruebasY[3] = diff200.count()*1000;
    //------------------------------------------------------------------
    auto start400 = std::chrono::high_resolution_clock::now();
    mergeSort(prueba400,0,n400-1);
    auto end400 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff400 = end400 - start400;

    std::cout << diff400.count()*1000 << std::endl;

    valoresPruebasY[4] = diff400.count()*1000;
    //------------------------------------------------------------------
    auto start800 = std::chrono::high_resolution_clock::now();
    mergeSort(prueba800,0,n800-1);
    auto end800 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff800 = end800 - start800;

    std::cout << diff800.count()*1000 << std::endl;

    valoresPruebasY[5] = diff800.count()*1000;




    Grapher(valoresPruebasX,valoresPruebasY,"mergeSort.txt","plot 'mergeSort.txt' using 1:2:(sprintf(\"(%d, %d)\", $1, $2)) with labels point pt 7 offset char 1,1 font ',14' notitle,\  'mergeSort.txt' w linespoint , '' with labels");

    //Termina Prueba------------------------------------------------------------------------------
}


#endif //ANALISIS_DE_ALGORITMOS_MERGESORT_H
